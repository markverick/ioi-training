#include<stdio.h>
int main(){
    double n,x,cost;

    printf("Enter weight for buying : ");
    scanf("%lf",&n);
    x = n*20;
    if(x<100&&x>50){
        cost=x*0.97;
        printf("Cost = %lf",cost);
    }
    if(x<200&&x>=100){
        cost=x*0.95;
        printf("Cost = %lf",cost);
    }
    if(x>=200){
        cost=x*0.9;
        printf("Cost = %lf",cost);
    }
    else{
        printf("Cost = %lf",x);
    }
    scanf(" ");
}
