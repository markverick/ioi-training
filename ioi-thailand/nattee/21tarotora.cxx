#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int c[135],v[135],t[135],dp[135][135][135];
int main()
{
	// freopen("out.txt","w",stdout);
	// freopen("in.txt","r",stdin);
	int n,m,i,j,k,mc,l;
    scanf("%d %d",&m,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&c[i],&v[i],&t[i]);
    }
    for(i=0;i<=105;i++)
        for(j=0;j<=105;j++)
            for(k=0;k<105;k++)
                dp[i][j][k]=-MI;
    dp[0][0][0]=0;
    for(i=1;i<=n;i++)
    {
        for(l=n;l>=1;l--)
        {
            for(j=m;j>=0;j--)
            {
                for(k=i;k>=0;k--)
                {
//                    if(j+c[i]<=m)
//                        dp[l][j+c[i]][k+t[i]]=max(dp[l][j+c[i]][k+t[i]],dp[l-1][j][k]+v[i]);
                    if(j-c[i]>=0&&k-t[i]>=0)
                        dp[l][j][k]=max(dp[l][j][k],dp[l-1][j-c[i]][k-t[i]]+v[i]);
                }
            }
        }
    }
    mc=0;
    int a,b;
    for(k=0;k<=n;k++)
    {
        for(j=0;j<=m;j++)
        {
            for(i=0;i<=k;i++)
            {
                a=i;b=k-i;
                if(a>b)swap(a,b);
                if(b<=2*a+2)
                {
                    mc=max(mc,dp[k][j][i]);
//                    if(dp[k][j][i]==mc)
//                        printf("%d %d %d\n",k,j,i);
                }
            }
        }

    }
}
