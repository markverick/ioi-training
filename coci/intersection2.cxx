#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
pair<int,int> p[50135];
vector<pair<int,int> > out;
map<pair<int,int> ,int> mp;
int cot=0;
void dp(int fs,int ls)
{
	if(fs==ls)
	{
		return;
	}
	int md=(fs+ls)/2,i;
	dp(fs,md);
	dp(md+1,ls);
	for(i=md+1;i<=ls;i++)
	{
		out.emplace_back(p[md].X,p[i].Y);
	}
	out.emplace_back(p[md].X,p[md].Y);
	return;

}
int main()
{
	//freopen("out.txt","w",stdout);
	// freopen("in.txt","r",stdin);
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d %d",&p[i].X,&p[i].Y),mp[p[i]]=1;
	sort(&p[1],&p[n+1]);
	dp(1,n);
	sort(out.begin(),out.end());
	out.resize(unique(out.begin(),out.end())-out.begin());
	j=0;
	for(i=0;i<out.size();i++)
	{
		if(mp.find(out[i])!=mp.end())
			continue;
		printf("%d %d\n",out[i].X,out[i].Y);
		j++;
	}
	// printf("=%d\n",j);
}