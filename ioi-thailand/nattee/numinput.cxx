#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> v;
int a[1135],hsh[1135],jum[1135][1135],m,n;
int dp(int idx,int ch)
{
    if(jum[idx][ch]>=0)return jum[idx][ch];
    if(idx==v.size()-1)
    {
        if(ch==n)
            return 1;
        return 0;
    }
//    printf("%d %d\n",idx,ch);
    int sm=0;
    if(!hsh[idx+1]||v[idx+1]==ch)
        sm+=dp(idx+1,ch);
    if(ch<n)
    {
        if(!hsh[idx+1]||v[idx+1]==ch+1)
            sm+=dp(idx+1,ch+1);
    }
    sm%=9901;
    return jum[idx][ch]=sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	memset(jum,-1,sizeof jum);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&j);
        while(j--)
            v.emplace_back(i);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
        a[i]--;
        hsh[a[i]]=1;
    }
    printf("%d",dp(0,1));
}
