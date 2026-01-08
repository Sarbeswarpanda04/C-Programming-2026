#include<stdio.h>
int main(){
    int a,b;
    printf("Enter First Number:");
    scanf("%d",&a);
    printf("Enter Second Number:");
    scanf("%d",&b);
    int remainder = a % b;
    printf("The remainder when %d is divided by %d is %d", a, b, remainder);
    return 0;
}