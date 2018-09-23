#include<stdio.h>

int main(){
    int n,cot=0;
    int i,j,k;
    scanf("%d",&n);
    while(cot<=n){
        for(i=0;i<=25;i++,cot++){
            printf("%c ",i+'A');
        }
    }

    scanf(" ");
}
