#include<bits/stdc++.h>
#define MI 1000000000
#define M 1000000007
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,a[2135],jum[4][2005][5];
vector<int> adj[5];
int dp(int ch,int idx,int bit)
{
    if(jum[ch][idx][bit]>=0)
        return jum[ch][idx][bit];
    if(idx==n&&__builtin_popcount(bit)==2)
        return 1;
    if(idx>=n)
        return 0;
//    printf("%d %d %d\n",ch,idx,y,z);
    int sm=0,i,j,k;
    for(i=0;i<adj[ch].size();i++)
    {
        k=adj[ch][i];
        for(j=1;j<=a[k];j++)
        {
            if(k==1)
                sm+=dp(k,idx+j,bit);
            else
            {
                sm+=dp(k,idx+j,(1<<(k-2))|bit);
            }
            sm%=M;
        }
    }
    return jum[ch][idx][bit]=sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,sm=0;
	memset(jum,-1,sizeof jum);
	scanf("%d",&n);
	for(i=1;i<=3;i++)
        scanf("%d",&a[i]);
    adj[1].emplace_back(2);
    adj[2].emplace_back(3);
    adj[1].emplace_back(3);
    adj[3].emplace_back(1);
    for(i=1;i<=a[1];i++)
        sm+=dp(1,i,0),sm%=M;
    printf("%d",sm);
}
