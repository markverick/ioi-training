/*
TASK: Count palindromes
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define EPS 1e-9
#define ALL(x) (x).begin(),(x).end()
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back((x))
#define FOR(i,st,ed) for(int (i)=(st);(i)<(ed);(i)++)
typedef pair<int,int> PII;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef long long LL;

int N,M=1000000007,T;
int tb[1005];
char chk[1005][1005];
string s; // palin
bool isPalin(int x,int y)
{
// printf("%d %d\n",x,y);
if(x==y || x-y==1) return 1;
if(chk[x][y]!=-1)
return chk[x][y];
if(s[x-1]!=s[y-1])
return chk[x][y]=0;
return chk[x][y]=isPalin(x+1,y-1);
}
int dp(int x)
{
if(x==0) return 1;
if(tb[x]!=-1)
return tb[x];
int k=0;
for(int i=x;i>=0;i--)
{
if(isPalin(i,x))
k+=dp(i-1),k%=M;
}
return tb[x]=k;
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
//freopen("xxx.in","r",stdin);
//freopen("xxx.out","w",stdout);
int i,j,k;
cin >> s;
memset(tb,-1,sizeof tb);
memset(chk,-1,sizeof chk);
cout << dp(s.size()) << '\n';
}
