#include<bits/stdc++.h>
using namespace std;
long long n,m,p;
long long dx[8]={0,0,1,1,1};
long long dy[8]={-1,1,-1,0,1};
long long mat[35][8];
unordered_map<long long,long long> mp;
vector<long long> jum[35][35];
vector<long long> v,zero,blk;
vector<long long> Pow(long long q,long long p)
{
    if(jum[q][mp[p]].size()>0)
    {
        return jum[q][mp[p]];
    }
    long long i,j,tmp;
    vector<long long> base=zero;
    base[q]=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            base[(j+1)%m]=min(base[(j+1)%m],base[j]+mat[j][1]);
            tmp=(j-1)<0?j-1+m:j-1;
            base[tmp]=min(base[tmp],base[j]+mat[j][0]);
        }
    }
    if(p==1)
    {
        return base;
    }
    vector<long long> a=Pow(q,p/2),s=zero,b=zero,c[33];
    for(i=0;i<m;i++)
    {
        c[i]=Pow(i,p/2);
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            b[i]=min(b[i],a[j]+c[j][i]+mat[j][3]);
            b[i]=min(b[i],a[j]+c[(j+1)%m][i]+mat[j][4]);
            b[i]=min(b[i],a[j]+c[(j-1)<0?j-1+m:j-1][i]+mat[j][2]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            b[(j+1)%m]=min(b[(j+1)%m],b[j]+mat[j][1]);
            tmp=(j-1)<0?j-1+m:j-1;
            b[tmp]=min(b[tmp],b[j]+mat[j][0]);
        }
    }
    if(p%2)
    {
        vector<long long> d=zero;
        for(i=0;i<m;i++)
        {
            d[i]=min(d[i],b[i]+mat[i][3]);
            d[(i+1)%m]=min(d[(i+1)%m],b[i]+mat[i][4]);
            tmp=(i-1)<0?i-1+m:i-1;
            d[tmp]=min(d[tmp],b[i]+mat[i][2]);
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                d[(j+1)%m]=min(d[(j+1)%m],d[j]+mat[j][1]);
                tmp=(j-1)<0?j-1+m:j-1;
                d[tmp]=min(d[tmp],d[j]+mat[j][0]);
            }
        }
        return jum[q][mp[p]]=d;
    }
    return jum[q][mp[p]]=b;
}
int main()
{
    long long i,j;
    scanf("%lld %lld %lld",&n,&m,&p);
    i=n;j=0;
    while(i>0)
    {
        mp[i]=j++;
        i/=2;
    }
    mp[i]=j++;
    for(i=0;i<m;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%lld",&mat[i][j]);
        }
    }
    for(i=0;i<m;i++)
        zero.emplace_back(1000000000000000000);
    vector<long long> out=Pow(0,n);
    printf("%lld\n",out[p]%1000003);
}
