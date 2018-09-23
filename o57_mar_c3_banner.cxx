#include<bits/stdc++.h>
#define MI 1000000000
using namespace std;
int n,m,jum[333][333],hsh[333][333];
int dp(int fs,int ls)
{
	if(jum[fs][ls]>=0)return jum[fs][ls];
	int i,mc=0;
	if(fs==ls)
		return jum[fs][ls]=hsh[fs][ls];
	for(i=fs;i<ls;i++)
	{
		mc=max(mc,dp(fs,i)+dp(i+1,ls)+hsh[fs][ls]);
	}
	return jum[fs][ls]=mc;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,a,b;
	memset(jum,-1,sizeof jum);
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		hsh[a][b]++;
	}
	printf("%d\n",m-dp(1,n));
}