/*
Take 3 numbers input and tell if they can be the sides of a triangle
*/

#include<stdio.h>
int main(){
    
    int a,b,c;
    printf("Enter the 1st Side :");
    scanf("%d",&a);
    printf("Enter the 2nd Side :");
    scanf("%d",&b);
    printf("Enter the 3rd Side :");
    scanf("%d",&c);

    if (a<0 || b<0 || c<0){
        printf("Triangles sides can not be negative \n please enter positive value");
    }
    else if(a+b>=c && a+c>=b && b+c>=a){
        printf("%d,%d,%d can be a side of a triangle",a,b,c);
    }

    return 0;
}