#include<stdio.h>
int main(){
    int r,s,t,i,n,x;
    scanf("%d %d %d %d",&r,&s,&t,&n);
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        if(x>=r){
            x-=r;
            if(x%(s+t)<=s)printf("yes\n");
            else printf("no\n");
        }
        else printf("no\n");
    }
}
