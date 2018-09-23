#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
#define I p[i].X[idx]-'a'
#define J p[j].X[idx]-'a'
#define K p[k].X[idx]-'a'
#define FS p[fs].X[idx]-'a'
#define LS p[ls].X[idx]-'a'
using namespace std;
pair<string,int> p[30135];
int mat[30][30];
int hsh[28],n;
string s[30135];
vector<pair<int,string> > out;
int dfs(int idx)
{
	hsh[idx]=1;
	int mc=0;
	// printf("!%c\n",'a'+idx);
	for(int i=0;i<26;i++)
	{
		if(idx==i)continue;
		if(!mat[idx][i])continue;
		// printf("mat[%c][%c]=%d",'a'+idx,'a'+i,mat[idx][i]);
		if(hsh[i]==1)
		{
			return 1;
		}
		else if(hsh[i]==0)
			mc=max(mc,dfs(i));
	}
	hsh[idx]=2;
	// printf("!%c %d\n",'a'+idx,mc);
	return mc;
}
int chk()
{
	memset(hsh,0,sizeof hsh);
	for(int i=0;i<26;i++)
	{
		// printf("> %c\n",'a'+i);
		if(hsh[i])continue;
		if(dfs(i))
			return 1;
	}
	return 0;
}
void print()
{
	int i,j;
	for(i=0;i<26;i++)
	{
		for(j=0;j<26;j++)
		{
			if(i==j)continue;
			if(mat[i][j])
				printf("%c-> %c\n",'a'+i,'a'+j);
		}
	}
	printf("\n");
}
void div(int idx,int fs,int ls)
{
	int i,j=fs,k;
	// printf("%d %d %d\n",idx,fs,ls);
	// print();
	if(fs==ls)
	{
		if(!chk())
		{
			out.emplace_back(p[fs].Y,p[fs].X);
		}
		return;
	}
	if(FS==-1)
	{
		out.emplace_back(p[fs].Y,p[fs].X);
		return;
	}
	int hsh[26];
	memset(hsh,0,sizeof hsh);
	for(i=fs;i<=ls;i++)
		hsh[I]=1;
	for(i=fs+1;i<=ls;i++)
	{
		if(p[i].X[idx]!=p[i-1].X[idx])
		{
			for(k=0;k<26;k++)
				mat[J][k]+=hsh[k];
			div(idx+1,j,i-1);
			for(k=0;k<26;k++)
				mat[J][k]-=hsh[k];
			j=i;
		}
	}
	for(k=0;k<26;k++)
		mat[LS][k]+=hsh[k];
	div(idx+1,j,ls);
	for(k=0;k<26;k++)
		mat[LS][k]-=hsh[k];
}
int main()
{
	freopen("first.out","w",stdout);
	freopen("first.in","r",stdin);
	int i,j,k,len=0;
	cin >> n;
	for(i=1;i<=n;i++)
		cin >> s[i],p[i]=MP(s[i],i),len=max(len,(int)s[i].size());
	sort(&p[1],&p[n+1]);
	for(i=1;i<=n;i++)
	{
		p[i].X.resize(len,'a'-1);
		// cout << p[i].X << "\n";
	}
	div(0,1,n);
	sort(out.begin(),out.end());
	printf("%d\n",out.size());
	for(i=0;i<out.size();i++)
	{
		for(j=0;j<out[i].Y.size();j++)
		{
			if(out[i].Y[j]=='a'-1)break;
			cout << out[i].Y[j];
		}
		cout << "\n";
		// cout << out[i].Y << "\n";
	}
}