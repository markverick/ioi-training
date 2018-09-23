#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int a[100135],sq[100135],blk,R[100135],L[100135],b[100135],d[320];
pair<int,int> dp[100135];
vector<int> v;
int main()
{
    int n,m,i,j,x,y,p,q;
    scanf("%d %d",&n,&m);
    blk=ceil(sqrt(n));
//    printf("%d\n",blk);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i] );
    }
    dp[0]={a[0],-1};
    dp[1]={a[1],-1};
    for(i=2;i<n;i++)
    {
        if(dp[i-2].X+a[i]>dp[i-1].X)
        {
            dp[i].X=dp[i-2].X+a[i];
            dp[i].Y=i-2;
        }
        else
        {
            dp[i].X=dp[i-1].X;
            dp[i].Y=dp[i-1].Y;
        }
    }
//    v.emplace_back
    if(dp[n-1].X>dp[n-2].X)
        j=n-1;
    else
        j=n-2;
    while(j>=0)
    {
        v.emplace_back(j);
        j=dp[j].Y;
    }
    for(i=0;i<v.size();i++)
    {
        if(v[i]%blk==0)
            L[v[i]/blk]=1;
        if(v[i]%blk==blk-1)
            R[v[i]/blk]=1;
        sq[v[i]/blk]+=a[v[i]];
    }
//    for(i=0;i<=(n-1)/blk;i++)
//    {
//        printf("%d <- %d -> %d\n",L[i],sq[i],R[i]);
//    }
    for(j=1;j<=m;j++)
    {
        scanf("%d %d",&x,&y);
        a[x]=y;
        if(L[x/blk]==1&&R[x/blk]==1)
        {
            memset(d,0,sizeof d);
            d[1]=a[x/blk+1];
            for(i=2;i<blk-1;i++)
                d[i]=max(d[i-2]+a[x/blk+i],d[i-1]);
            p=blk-2<0?0:d[blk-2];
            memset(d,0,sizeof d);
            d[0]=a[x/blk];
            d[1]=a[x/blk+1];
            for(i=2;i<blk;i++)
                d[i]=max(d[i-2]+a[x/blk+i],d[i-1]);
            q=d[blk-1];
            sum=0;
            if(p>=q)
            {
                for(i=0;i<=(n-1)/blk;i++)
                {
                  sum+=sq[i];
                }
            }
        }
    }
}
