#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int jum[105][105][3][3],tf[266],m=0;
char s[135];
int mex(vector<int> &v)
{
	int i=0;
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for(i=0;i<v.size();i++)
		if(i!=v[i])break;
	return i;
}
int dp(int L,int R,int l,int r)
{
	if(L>R)return 0;
	// printf("[%d] %d --- %d [%d]\n",l,L,R,r);
	if(jum[L][R][l][r]>=0)return jum[L][R][l][r];
	int mn=1,i;
	if(L==R)
	{
		return (l==r||l==2||r==2);
	}
	vector<int> v,u,w;
	int a,b;
	if(l==2)
		v.emplace_back(dp(L+1,R,0,r)),
		v.emplace_back(dp(L+1,R,1,r));
	else
		v.emplace_back(dp(L+1,R,1-l,r));
	if(r==2)
		v.emplace_back(dp(L,R-1,l,0)),
		v.emplace_back(dp(L,R-1,l,1));
	else
		v.emplace_back(dp(L,R-1,l,1-r));
	for(i=L+1;i<R;i++)
	{
		// v.emplace_back(dp(L,i-1,l,0));
		// v.emplace_back(dp(i+1,R,0,r));
		// v.emplace_back(dp(L,i-1,l,1));
		// v.emplace_back(dp(i+1,R,1,r));
		v.emplace_back(dp(L,i-1,l,0)^dp(i+1,R,0,r));
		v.emplace_back(dp(L,i-1,l,1)^dp(i+1,R,1,r));
	}
	return jum[L][R][l][r]=mex(v);
}
int main()
{
	// freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int T,i,j,k,n,x=0;
	scanf("%d",&T);
	memset(jum,-1,sizeof jum);
	tf[0]=2;
	tf['X']=1;
	tf['O']=0;
	while(T--)
	{
		scanf("%s",s+1);x=0;m=0;
		n=strlen(s+1);
		s[n+1]=0;
		j=0;
		for(i=1;i<=n;i++)
			if(s[i]=='O'||s[i]=='X')m++;
		m%=2;
		for(i=1;i<=n+1;i++)
		{
			if(s[i]=='X'||s[i]=='O'||s[i]==0)
				x^=dp(j+1,i-1,tf[s[j]],tf[s[i]]),j=i;
			// printf("!");

		}
		if(x)x=1;
		if(x^m)
			printf("Possible.\n");
		else
			printf("Impossible.\n");
	}
}