#include<stdio.h>
int main(){
    int i = 2*3/4+4/4+8-2+5/8;
    printf("%d\n", i);
    return 0;
}


//step by step evaluation:
//1. Multiplication and Division (from left to right):
//   2 * 3 = 6
//   6 / 4 = 1 (integer division)
//   4 / 4 = 1
//   5 / 8 = 0 (integer division)
//   So the expression now looks like:
//   1 + 1 + 8 - 2 + 0
//2. Addition and Subtraction (from left to right):
//   1 + 1 = 2
//   2 + 8 = 10
//   10 - 2 = 8
//   8 + 0 = 8
//Final result: 8