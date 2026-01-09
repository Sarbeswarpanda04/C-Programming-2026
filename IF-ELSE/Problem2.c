/*Given the length and breadth of a rectangle
write a program to find whether the area of 
the rectangle is greater than its perimeter 
*/

#include<stdio.h>
int main(){
    
    int length,breadth;
    printf("Enter the length :");
    scanf("%d",&length);
    printf("Enter the breadth :");
    scanf("%d",&breadth);   


    int area,perimeter;

    area = length * breadth;
    perimeter = 2*(length+breadth);
 
    if (area>perimeter){
        printf("area is greater than perimeter");
    }
    else if (area==perimeter){
        printf("area is equal to perimeter");
    }
    else {
        printf("area is smaller than perimeter");
    }

    return 0;
}