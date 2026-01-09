/*
Take Positive integer input and tell if it is divisible by 5 & 3.
*/

#include<stdio.h>
int main(){
    
    int num;
    printf("Enter the Number :");
    scanf("%d",&num);

    if (num<0){
        printf("You Entered a Negative Number \nPlease enter a positive number");
    }
    else if(num%15==0){
        printf("%d is Divisible by 5 & 3",num);
    }
    else {
        printf("%d is not Divisible by 5 & 3",num);
    }
    return 0;
}
