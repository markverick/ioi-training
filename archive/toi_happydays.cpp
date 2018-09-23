#include<stdio.h>
int main(){
    int n,x[400];
    int i,j,k,c=0;
    scanf("%d",&n);
    x[0]=-200;
    for(i=1;i<=n;i++){
        scanf("%d",&x[i]);
        if(x[i]>=80||(x[i]-x[i-1]>=10&&x[i]>=20&&i!=1)){
            c++;
        }
    }
    printf("%d",c);


}
