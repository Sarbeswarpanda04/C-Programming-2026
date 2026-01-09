/*
Take positive integer input and tell if 
it is a three digit number or not
*/

#include<stdio.h>
int main(){
    
    int num;
    printf("Enter the Number :");
    scanf("%d",&num);

    if (num<0){
        printf("You Entered a Negative Number \n Please enter a positive number");
    }
    else if(num>=100 && num <=999){
        printf("%d is a three digit number",num);
    }
    else {
        printf("%d is not a three digit number",num);
    }
    return 0;
}
