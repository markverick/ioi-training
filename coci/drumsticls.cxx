#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<pair<int,int> > adj[1531];
int d[1531],p[1531];
priority_queue<pair<int,int> > pq;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,m,a,b,c;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        adj[a].emplace_back(b,c);
    }
}
