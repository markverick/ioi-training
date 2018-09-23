#include<stdio.h>
int main(){
    int n;
    int x[10000];
    int lo,cot=0;
    int i,j=0,k;
    int *p;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&x[i]);
    }
    lo=x[1];
    while(cot<n){
        lo=9999999;
        x[j]=9999999;
        for(i=1;i<=n;i++){
            if(lo>=x[i]){
                lo=x[i];
                j=i;
            }
        }
        x[j]=9999999;
        p=&lo;
        printf("%d ",*p);
        cot++;
    }
    scanf(" ");

}
