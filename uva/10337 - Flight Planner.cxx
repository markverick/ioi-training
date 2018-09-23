#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int maps[12][1135],jum[1135][12],n;
int dp(int idx,int al)
{
    if(jum[idx][al]>=0)
        return jum[idx][al];
    if(idx==n+1)
    {
        if(al==0)
            return 0;
        return MI;
    }
    int mn=MI;
    mn=min(mn,dp(idx+1,al)+30-maps[al][idx]);
    if(al>0)
        mn=min(mn,dp(idx+1,al-1)+20-maps[al][idx]);
    if(al<9)
        mn=min(mn,dp(idx+1,al+1)+60-maps[al][idx]);
    return jum[idx][al]=mn;
}
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int T,i,j,k;
	scanf("%d",&T);
	while(T--)
    {
        memset(jum,-1,sizeof jum);
        scanf("%d",&n);
        n/=100;
        for(i=9;i>=0;i--)
        {
            for(j=1;j<=n;j++)
                scanf("%d",&maps[i][j]);
        }
        printf("%d\n\n",dp(1,0));
    }
}
