#include<stdio.h>
int main() {
    float physics, chemistry, biology, mathematics, computer_science;
    printf("enter marks in physics: ");
    scanf("%f", &physics);
    printf("enter marks in chemistry: ");
    scanf("%f", &chemistry);
    printf("enter marks in biology: ");
    scanf("%f", &biology);
    printf("enter marks in mathematics: ");
    scanf("%f", &mathematics);
    printf("enter marks in computer science: ");
    scanf("%f", &computer_science);

    float total;
    total = (physics + chemistry +biology + mathematics + computer_science)/5;
    printf("The percentage of 5 subjects is: %f %%", total);
    return 0;
}



//Author: Sarbeswar Panda