#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int a[500135],p[500135],n,ste[500135],seg[4000135],x,val;
vector<int> adj[500135],b;
pair<int,int> pos[500135];
void dfs(int idx)
{
    int i;
    ste[idx]=1;
    for(i=0;i<adj[idx].size();i++)
    {
        if(ste[adj[idx][i]])
            continue;
        pos[adj[idx][i]].X=b.size();
        b.emplace_back(adj[idx][i]);
        dfs(adj[idx][i]);
        pos[idx].Y=b.size();
        b.emplace_back(idx);
    }
}
void update(int id,int fs,int ls)
{
    int md=(fs+ls)/2;
    if(fs==ls)
    {
        seg[id]+=val;
        return;
    }
    if(x<=md)
        update(id*2,fs,md);
    else
        update(id*2+1,md+1,ls);
    seg[id]=seg[id*2]+seg[id*2+1];
}
int sum(int id,int fs,int ls)
{
    int md=(fs+ls)/2;
    if(fs==ls)
        return seg[id];
    if(x>md)
        return seg[id*2]+sum(id*2+1,md+1,ls);
    return sum(id*2,fs,md);
}
int main()
{
    int m,i,j,k;
    scanf("%d %d %d",&n,&m,&a[1]);
    for(i=2;i<=n;i++)
    {
        scanf("%d %d",&a[i],&p[i]);
        adj[p[i]].emplace_back(i);
    }
    b.emplace_back(1);
    dfs(1);
    char ch[3];
    for(i=1;i<=m;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='p')
        {
            scanf("%d %d",&k,&val);
            if(!adj[k].empty())
            {
                x=pos[k].X+1;
                update(1,0,b.size()-1);
                x=pos[k].Y;val=-val;
                update(1,0,b.size()-1);
            }
        }
        else
        {
            scanf("%d",&k);
            x=pos[k].X;
            printf("%d\n",a[k]+sum(1,0,b.size()-1));
        }
    }
}
