/*if cost price and selling price of an item is input through
the keyboard, write a program to determine wheather the seller
has made profit or incurred loss. Also determine how much profit 
he made or loss he incurred */

#include<stdio.h>
int main(){
    
    int cp,sp;
    printf("Enter the Cost Price :");
    scanf("%d",&cp);
    printf("Enter the Selling Price :");
    scanf("%d",&sp);   
 
    if (sp>cp){
        printf("Yay! you made a Profit of %d",sp-cp);
    }
    if (sp == cp){
        printf("No Profit No Loss !");
    }
    else {
        printf("Sorry there are a loss of %d",cp-sp);
    }

    return 0;
}
