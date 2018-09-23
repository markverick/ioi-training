#include<bits/stdc++.h>
long long sum2[120000];
long long sum;
int ar[120000];
int main(){
    int i,j,k;
    int t;
    int n,q;
    int s,e;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        sum=0;
        //idx=0;
        scanf("%d %d",&n,&q);
        for(j=0;j<n;j++){
            scanf("%d",&ar[j]);
            sum+=ar[j];
            sum2[j]=sum;
        }
        for(j=0;j<q;j++){
//            sub=0;

            scanf("%d %d",&s,&e);
            if(e>n){
                e=q;
            }
            //if(s-1<0)sum2[0]
            if(s>0){
                printf("%lld\n",sum2[e]-sum2[s-1]);
            }
            else{
                printf("%lld\n",sum2[e]);
            }
            /*for(k=s;k<=e;k++){
                sum+=ar[k];
            }*/
            //printf("%d\n",sum);

        }
        printf("\n");
    }
    scanf(" ");

}
