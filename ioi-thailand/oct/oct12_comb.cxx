#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,m,L,out[14],jum[14][14];
int dp(int idx,int hi)
{
    if(jum[idx][hi]>=0)
        return jum[idx][hi];
    if(idx==m)
        return jum[idx][hi]=1;
    int sum=0,i,k;
    for(i=hi;m-idx<=n-i;i++)
    {
        sum+=dp(idx+1,i+1);
    }
    return jum[idx][hi]=sum;
}
void dfs(int idx,int hi)
{
    if(idx==m)
        return;
    int sum=0,i;
    for(i=hi;m-idx<=n-i;i++)
    {
        if(sum+jum[idx+1][i+1]>=L)
        {
            printf("%d ",i+1);
            L-=sum;
            dfs(idx+1,i+1);
            return;
        }
        sum+=jum[idx+1][i+1];
    }
    return;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	memset(jum,-1,sizeof jum);
	scanf("%d %d %d",&n,&m,&L);
	dp(0,0);
//    for(i=0;i<m;i++)
//        printf("%d ",out[i]+1);
    dfs(0,0);
}
