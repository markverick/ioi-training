#include<stdio.h>
int main(){
    int x,k[100000];
    int i,j,n,c=0;
    scanf("%d",&n);
    x=n;
    for(i=1;i<=n;i++){
        k[i]=x%2;
        x = x/2;
    }
    for(i=n;i>0;i--){
        if(k[i]!=0){
            c=1;
        }
        if(c!=0){
            printf("%d",k[i]);
        }
    }
    scanf(" ");
}
