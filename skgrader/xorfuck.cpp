#include<bits/stdc++.h>
using namespace std;
long long sum[120000];
//long long hsh[120000];
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            long long a;
            scanf("%lld",&a);
            sum[i]=a^sum[i-1];
        }
        long long ans=0;
        for(j=0;j<32;j++)
        {
            long long x=1,y=0;
            for(i=1;i<=n;i++)
            {

                //printf("%d\n",sum[i]&(1<<j));
                if((sum[i]&(1<<j))==0)
                {
                    //printf("X");
                    x++;
                }
                else
                {
                    //printf("Y");
                    y++;
                }

                //system("pause");
            }
            ans+=x*y*(1<<j);
            //printf("%d %lld %lld\n",j,x,y);

        }
        printf("%lld\n",ans);
    }
}
