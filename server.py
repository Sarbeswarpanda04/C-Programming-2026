import json
import os
from http.server import SimpleHTTPRequestHandler
from socketserver import TCPServer
from urllib.parse import parse_qs, urlparse

BASE_DIR = os.path.abspath(os.path.dirname(__file__))


def safe_join(base_dir: str, user_path: str) -> str:
    user_path = user_path.replace("\\", "/")
    user_path = user_path.lstrip("/")

    candidate = os.path.abspath(os.path.join(base_dir, user_path))
    if os.path.commonpath([base_dir, candidate]) != base_dir:
        raise ValueError("Invalid path")
    return candidate


def build_tree(base_dir: str):
    root = {"name": os.path.basename(base_dir) or base_dir, "path": "", "dirs": [], "files": []}

    dir_nodes = {"": root}

    for current_dir, dirnames, filenames in os.walk(base_dir):
        rel_dir = os.path.relpath(current_dir, base_dir)
        if rel_dir == ".":
            rel_dir = ""

        node = dir_nodes.get(rel_dir)
        if node is None:
            node = {"name": os.path.basename(current_dir), "path": rel_dir, "dirs": [], "files": []}
            dir_nodes[rel_dir] = node

        # Hide dot-directories (e.g. .git, .vscode) and common local caches
        dirnames[:] = [d for d in dirnames if not d.startswith(".") and d != "__pycache__"]
        filenames[:] = [f for f in filenames if not f.startswith(".")]

        dirnames.sort(key=str.lower)
        filenames.sort(key=str.lower)

        for d in dirnames:
            child_rel = f"{rel_dir}/{d}" if rel_dir else d
            child_node = {"name": d, "path": child_rel, "dirs": [], "files": []}
            node["dirs"].append(child_node)
            dir_nodes[child_rel] = child_node

        for f in filenames:
            rel_file = f"{rel_dir}/{f}" if rel_dir else f
            node["files"].append({"name": f, "path": rel_file})

    return root


class Handler(SimpleHTTPRequestHandler):
    def do_GET(self):
        parsed = urlparse(self.path)

        # Silence harmless browser probes
        if parsed.path in (
            "/favicon.ico",
            "/.well-known/appspecific/com.chrome.devtools.json",
            "/service-worker.js",
            "/manifest.json",
        ):
            self.send_response(204)
            self.end_headers()
            return

        if parsed.path == "/api/tree":
            tree = build_tree(BASE_DIR)
            payload = json.dumps(tree)
            self.send_response(200)
            self.send_header("Content-Type", "application/json; charset=utf-8")
            self.send_header("Cache-Control", "no-store")
            self.end_headers()
            self.wfile.write(payload.encode("utf-8"))
            return

        if parsed.path == "/api/file":
            qs = parse_qs(parsed.query)
            req_path = qs.get("path", [""])[0]
            try:
                abs_path = safe_join(BASE_DIR, req_path)
            except ValueError:
                self.send_error(400, "Invalid path")
                return

            if not os.path.isfile(abs_path):
                self.send_error(404, "File not found")
                return

            # Keep it simple: serve as text
            try:
                with open(abs_path, "rb") as f:
                    content = f.read()
            except OSError:
                self.send_error(500, "Could not read file")
                return

            self.send_response(200)
            self.send_header("Content-Type", "text/plain; charset=utf-8")
            self.send_header("Cache-Control", "no-store")
            self.end_headers()
            self.wfile.write(content)
            return

        return super().do_GET()


def main():
    port = int(os.environ.get("PORT", "8000"))
    with TCPServer(("127.0.0.1", port), Handler) as httpd:
        print(f"Serving: {BASE_DIR}")
        print(f"Open:    http://127.0.0.1:{port}/index.html")
        httpd.serve_forever()


if __name__ == "__main__":
    main()
