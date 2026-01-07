#include<stdio.h>
int main(){
    float number, square;
    printf("Enter a number: ");
    scanf("%f", &number);
    square = number * number;
    printf("The square of %f is %f", number, square);
    return 0;
}