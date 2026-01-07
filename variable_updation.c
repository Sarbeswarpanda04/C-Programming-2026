#include<stdio.h>
int main() {
    int x = 5;
    printf("Initial value of x: %d\n", x);
    x =7;
    printf("Updated value of x: %d\n", x);
    x =x + 3;
    printf("Final value of x after adding 3: %d\n", x);
    return 0;
}