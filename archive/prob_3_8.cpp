#include<stdio.h>
int main(){
    int x,y,k[100000];
    int i,j,n,c=0,b,m;
    printf("Enter Base : ");
    scanf("%d",&m);
    printf("Enter x : ");
    scanf("%d",&x);
    printf("Enter y : ");
    scanf("%d",&y);
    n=x+y;
    b=n;

    for(i=1;i<=n;i++){
        k[i]=b%m;
        b = b/m;
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
