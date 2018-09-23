#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,a[100],b[100],c[100],s[100],jum[600];
int dp(int bit)
{
    if(__builtin_popcount(bit)==9)
    {
        return 0;
    }
    if(jum[bit]>=0)
        return jum[bit];
    int i,mc=-MI;
    for(i=1;i<=n;i++)
    {
        if(!((1<<a[i])&bit) && !((1<<b[i])&bit) && !((1<<c[i])&bit) )
        {
            mc=max(mc,dp(bit|(1<<a[i])|(1<<b[i])|(1<<c[i]))+s[i]);
        }
    }
    return jum[bit]=mc;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,T=0;
	while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            return 0;
        memset(jum,-1,sizeof jum);
        T++;
        for(i=1;i<=n;i++)
        {
            scanf("%d %d %d %d",&a[i],&b[i],&c[i],&s[i]);
            a[i]--;b[i]--;c[i]--;
        }
        k=dp(0);
        if(k>=0)
            printf("Case %d: %d\n",T,k);
        else
            printf("Case %d: -1\n",T);
    }
}
