#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(){
    char n='0';
    char m='0';
    while(true){
        m = n;
        n = getch();
        if(n!=m){
            printf("%c",n);
        }

    }
    scanf(" ");
}
