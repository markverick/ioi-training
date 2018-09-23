#include<bits/stdc++.h>
using namespace std;
long long bb[2062500];
int main()
{
    int T,t,i,j,k;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        long long x;
        long long sum=0;
        long long val=0;
        scanf("%lld",&x);
        if(bb[x]>0){
            printf("%lld\n",bb[x]);
            continue;
        }
        for(i=1;i<=(x-1)/2;i++)
        {
            val=0;
            long long bc=i*(x-i);
            if(bb[bc]>0){
                sum+=bb[bc];
                continue;
            }
            for(j=1;j<bc;j++)
            {
                sum+=(bc-1)/j;
                val+=(bc-1)/j;
            }
            bb[bc]=val;
        }
        sum*=2;
        if(x%2==0)
        {
            long long bc=((x)/2)*((x)/2);
            for(j=1;j<bc;j++)
            {
                sum+=(bc-1)/j;
            }
        }
        printf("%lld\n",sum);
    }
}
