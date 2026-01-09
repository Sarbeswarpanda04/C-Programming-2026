/*
Take 3 positive integer input and print gretest of them
*/

#include<stdio.h>
int main(){
    
    int num1,num2,num3;
    printf("Enter the 1st Number :");
    scanf("%d",&num1);
    printf("Enter the 2nd Number :");
    scanf("%d",&num2);
    printf("Enter the 3rd Number :");
    scanf("%d",&num3);

    if (num1<0 || num2<0 || num3<0){
        printf("You Entered a Negative Number \nPlease enter a positive number");
    }
    else if(num1>num2 && num1>num3){
        printf("%d is Greatest",num1);
    }
    else if(num2>num3 && num2>num1){
        printf("%d is Greatest",num2);
    }
    else{
        printf("%d is Greatest",num3);
    }
    return 0;
}
