#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
int main(){
    char c;
    int i,j,k;
    int x[20];
    int sum=0;

    for(i=1;i<=16;i++){
        c = getche();
        x[i]=c-48;
    }
    printf("\nYou entered these number.\n");
    for(i=1;i<=16;i++){
        if(i%2==1){//even l from r <---
            x[i]*=2;
            if(x[i]>=10){
                x[i]=x[i]%10+x[i]/10;
            }
        }
        sum+=x[i];
    }
    if(sum%10==0){
        printf("Correct!");
    }
    else{
        printf("Incorrect!");
    }
    scanf(" ");



}
