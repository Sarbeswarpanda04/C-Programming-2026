//ascii value of all char.c
#include<stdio.h>
int main(){
    for(char ch = 33; ch < 127; ch++){
        printf("Character: %c  ASCII value: %d\n", ch, ch);
    }
    return 0;
}