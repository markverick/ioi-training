#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int jum[1135][1135];
int dp(int n,int k)
{
    if(jum[n][k]>=0)
        return jum[n][k];
    if(n==0)
    {
        return 0;
    }
    int mn=1,i;
    for(i=1;i<=k*2;i++)
    {
        if(n-i<0)
            break;
        mn=min(mn,dp(n-i,i));
    }
    return jum[n][k]=1-mn;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n;
	memset(jum,-1,sizeof jum);
	for(n=0;n<=200;n++)
    {
        for(i=1;i<=n;i++)
        {
            if(dp(n-i,i)==0)
            {
                printf("n = %d: %d\n",n,i);
                break;
            }
        }
    }
}
