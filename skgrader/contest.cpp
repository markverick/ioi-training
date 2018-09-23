#include<bits/stdc++.h>
using namespace std;
bool notPrime[1200000];
int prime[1200000];
int hsh[1200000];
int main()
{
    int m;
    scanf("%d",&m);
    int n;
    int i,j,k;
    int b;
    int sum=0;
    notPrime[1]=1;
    for(i=2;i<=100000;i++)
    {
        //chk[i]=1;
        if(!notPrime[i])
        {
            for(j=i+i;j<=100000;j+=i)
            {
                //chk[j]=1;
                notPrime[j]=1;
            }
        }
    }
    int idx=0;
    prime[idx++]=2;
    for(i=2;i<=100000;i++)
    {
        if(!notPrime[i])
        {
            //printf("%d\n",i);
            prime[idx++]=i;
        }
    }
    int len=idx;
    //printf("FF%d %d",len,prime[50]);
    //printf("==%d %d %d %d\n",prime[0],prime[1],prime[2],prime[3]);
    for(i=0;i<m;i++)
    {
        memset(hsh,0,sizeof hsh);
        int hi=0;
        sum=1;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&b);
            int b2=b;
            for(k=1;k<len&&prime[k]<=b2;k++)
            {

                if(b<=1)
                    break;

                while(b>0&&b%prime[k]==0)
                {
                    //printf("%d ",prime[k]);
                    hi=max(hi,k);
                    b/=prime[k];
                    hsh[prime[k]]++;
                }
            }
            //printf("\n");
        }
        int sum=1;

        //printf("%d %d\n",hi,prime[0]);
        for(k=1;k<=hi;k++)
        {
            sum*=(hsh[prime[k]]+1);
            //printf("%d %d, ",sum,prime[k]);
        }
        printf("%d\n",sum);

    }

}
