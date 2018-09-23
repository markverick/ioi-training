#include<stdio.h>
long long sum[1200000];
int main(){
    int i,j;
    int n,k,c;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&c);
        sum[i]=sum[i-1]+c;
        //printf("\nSUM = %d\n",sum[i]);
    }
    int d;
    for(i=1;i<=k;i++){
        scanf("%d",&c);
        for(j=1;true;j++){
            //printf("\n\n\t\tSUM = %d",sum[j]);
            if(sum[j]>c){
                d=j-1;
                break;
            }

        }
        printf("%d\n",d);
    }

}
