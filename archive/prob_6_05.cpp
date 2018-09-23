#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int n;
    int i,j,k;
    char ch='A',chb='A';
    scanf("%d",&n);
    srand(time(NULL));
    ch=rand()%26+'A';
    for(i=1;i<=n;i++){
        chb=rand()%26+'A';
        if(chb!=ch){
            printf("%c",ch);
        }
        ch=chb;

    }


}
