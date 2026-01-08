#include<stdio.h>
int main(){
    float n;
    printf("Enter the float number :");
    scanf("%f",&n);
    int a;
    a = n;
    float z = n - a;
    printf("The fractional part of the number %f is %f",n,z);
    return 0;
}