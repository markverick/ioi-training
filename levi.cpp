#include<bits/stdc++.h>

bool notPrime[13000];
long long prime[13000];
int main()
{
    int T,t,i,j,k,idx=0;
    notPrime[1]=1;
    for(i=2;i<=10000;i++)
    {
        if(notPrime[i]==0)
        {
            prime[idx++]=i;
        }
        for(j=i+i;j<=10000;j+=i)
        {
            notPrime[j]=1;
        }
    }
    /*for(i=0;i<100;i++)
    {
        printf("%d\n",prime[i]);
    }*/
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        int a;
        scanf("%d",&a);
        int cot=0;
        for(i=0;i<2000;i++)
        {
            if(a-2*prime[i]<=1)
                break;
            if(notPrime[a-2*prime[i]]==0)
            {
                cot++;
            }
        }
        printf("%d\n",cot);
    }
}
