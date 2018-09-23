#include<stdio.h>

using namespace std;
int prime[5000050];
int chk[5000050];
int hsh[5000050];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,i,j,t,n,a,idx=0,k;
    for(i=2;i<=5000000;i++)
    {
        if(!chk[i])
        {
            prime[idx++]=i;
            for(j=i+i;j<=500000;j+=i)
                chk[j]=1;
        }
    }
    scanf("%d",&T);
    int mc=0;
    for(t=1;t<=T;t++)
    {
        mc=0;
        scanf("%d",&n);
        memset(hsh,0,sizeof hsh);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            for(j=0;true;j++)
            {
                mc=max(mc,j);
                if(prime[j]>a)
                {
                    //hsh[j]++;
                    break;
                }

                while(a%prime[j]==0)
                {
                    a/=prime[j];
                    hsh[j]++;
                }
            }
        }
        int sum=1;
        for(i=0;i<mc;i++)
        {
            sum*=(hsh[i]+1);
        }
        printf("Case #%d\n%d\n",t,sum);
    }
}

