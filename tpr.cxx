#include<bits/stdc++.h>
using namespace std;
int hsh[10000];
vector<int> prime;
int main()
{
    int a,b,m,r,fu,i,j,k;
    scanf("%d %d %d %d",&a,&b,&m,&r);
    a-=r*3;b-=r*3;
    for(i=2;i<=b;i++)
    {
        fu=0;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                fu=1;break;
            }
        }
        if(fu==0)
        {
            if( (i-r)%m==0)
            {
               // printf("%d\n",i);
                prime.emplace_back(i-r);
            }
        }
    }
    for(i=0;i<prime.size();i++)
    {
        for(j=0;j<prime.size();j++)
        {
            for(k=0;k<prime.size();k++)
            {
                hsh[prime[i]+prime[j]+prime[k]]=1;
            }
        }
    }
    int cot=0;
    for(i=a;i<=b;i++)
    {
        if(hsh[i]==1)
            cot++;
    }
    printf("%d",cot);
}
