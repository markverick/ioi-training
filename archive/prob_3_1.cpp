#include<stdio.h>


int f(int x){
    return(x*x+3*x+1);
}
int main(){
    int x;
    printf("Enter x : ");
    scanf("%d",&x);
    printf("The f(x)=x^2+3x+1 = %d",f(x));
    scanf(" ");
}
