#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
long long mem[18][3][2],k;
long long mic(long long idx,long long op,long long ok)
{
    if(idx==-1&&ok==1)
        return 1;
    else if(idx==-1)
        return 0;
    if(mem[idx][op][ok]!=-1)
        return mem[idx][op][ok];
    long long sm=0,j;
    if(op==0)
    {
        sm+=mic(idx-1,0,ok);
        for(j=1;j<10;j++)
        {
            if(j==k)
                sm+=mic(idx-1,2,1);
            else
                sm+=mic(idx-1,2,ok);
        }
    }
    if(op==1)
    {
        for(j=0;j<10;j++)
        {
            if(j==k&&j==v[idx])
            {
                sm+=mic(idx-1,1,1);
                break;
            }
            else if(j==v[idx])
            {
                sm+=mic(idx-1,1,ok);
                break;
            }
            else if(j==k)
                sm+=mic(idx-1,2,1);
            else
                sm+=mic(idx-1,2,ok);
        }
    }
    if(op==2)
    {
        for(j=0;j<10;j++)
        {
            if(j==k)
                sm+=mic(idx-1,2,1);
            else
                sm+=mic(idx-1,2,ok);
        }
    }
    return mem[idx][op][ok]=sm;
}
int main()
{
    long long n,kb,sm,t,i,j;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        kb=n;
        v.clear();
        sm=0;
        while(kb!=0)
        {
            v.push_back(kb%10);
            kb/=10;
        }
        for(i=0;i<10;i++)
        {
            memset(mem,-1,sizeof mem);
            k=i;
            sm+=mic((int)v.size()-2,0,0);
            for(j=1;j<10;j++)
            {
                if(j==i&&j==v[v.size()-1])
                {
                    sm+=mic((int)v.size()-2,1,1);
                    break;
                }
                else if(j==v[v.size()-1])
                {
                    sm+=mic((int)v.size()-2,1,0);
                    break;
                }
                else if(j==i)
                    sm+=mic((int)v.size()-2,2,1);
                else
                    sm+=mic((int)v.size()-2,2,0);
            }
        }
        printf("%lld/%lld\n",sm/__gcd(sm,n*10),(n*10)/__gcd(sm,n*10));
    }
}
