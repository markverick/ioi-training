#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,a[17],jum[33000];
int dp(int bit)
{
    if(__builtin_popcount(bit)==n)
    {
        return 0;
    }
    if(jum[bit]>=0)
        return jum[bit];
    int i,j,k,mc=0;
    for(i=0;i<n;i++)
    {
        if((bit|(1<<i))==bit)
            continue;
        for(j=i+1;j<n;j++)
        {
            if((bit|(1<<j))==bit)
                continue;
            for(k=j+1;k<n;k++)
            {
                if((bit|(1<<k))==bit)
                    continue;
                if(a[i]+a[j]+a[k]>=20)
                    mc=max(mc,dp(bit|(1<<i)|(1<<j)|(1<<k))+1);
            }
        }
    }
    return jum[bit]=mc;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,t=0;
	while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            return 0;
        t++;
        memset(jum,-1,sizeof jum);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        printf("Case %d: %d\n",t,dp(0));
    }
}
