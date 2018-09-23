#include<stdio.h>
#include<stdlib.h>
int sum[120000];
int rev[120000];
int main(){
    int i,j;
    int n,k,c;
    scanf("%d %d",&n,&k);
    //printf("%d",k);
    //system("pause");
    for(i=1;i<=n;i++){
        scanf("%d",&c);
        sum[i]=sum[i-1]+c;
        for(j=0;j<c;j++){
            rev[sum[i]+j]=i;
        }
        //printf("\nSUM = %d C = %d J = %d  I = %d\n",sum[i],c,j,i);
    }
    int d;
    for(i=1;i<=k;i++){
        scanf("%d",&c);
        printf("%d\n",rev[c]);
    }

}
