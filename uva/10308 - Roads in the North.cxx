#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char str[135],*k;
vector<pair<int,int> > adj[10135];
pair<int,int> dfs(int idx,int pa)
{
    int i;
    pair<int,int> mc=MP(0,idx),p;
    for(i=0;i<adj[idx].size();i++)
    {
        if(adj[idx][i].X==pa)continue;
        p=dfs(adj[idx][i].X,idx);
        if(mc.X<p.X+adj[idx][i].Y)
        {
            mc.X=p.X+adj[idx][i].Y;
            mc.Y=p.Y;
        }
    }
    return mc;
}
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n=1,i,j,a,b,c;
	pair<int,int> p;
	while(gets(str))
    {
        if(strlen(str)==0)
        {
            p=dfs(1,0);
            i=p.Y;
            p=dfs(i,0);
            printf("%d\n",p.X);
            n=1;
            for(i=0;i<=10000;i++)
                adj[i].clear();
            continue;
        }
        sscanf(str,"%d %d %d",&a,&b,&c);
        n++;
        i=a;
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    p=dfs(1,0);
    i=p.Y;
    p=dfs(i,0);
    printf("%d\n",p.X);
}
