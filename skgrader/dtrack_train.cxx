#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
int n,k,m;
int a[1135][1135];
vector<int>::iterator it;
int state[1135];
int hsh[100135];
vector<int> head[100135];
queue<pair<int,int> > q;
int main()
{
    int i,j,u,w,id;
    scanf("%d %d %d",&n,&k,&m);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=k;j++)
        {
            scanf("%d",&a[i][j]);
            head[a[i][j]].emplace_back(i);
        }
    }
//    for(i=1;i<=n;i++)
//    {
//        sort(head[i].begin(),head[i].end());
//        auto it=unique(head[i].begin(),head[i].end());
//        head[i].resize(distance(head[i].begin(),it));
//
//    }
//    state[1]=1;
    q.emplace(1,1);
    while(!q.empty())
    {
        u=q.front().X;
        w=q.front().Y;
//        printf("%d %d\n",u,w);
        q.pop();
        if(u==n)
        {
            printf("%d",w);
            return 0;
        }
        for(i=0;i<head[u].size();i++)
        {
            if(state[head[u][i]])
                continue;
            state[head[u][i]]=1;
            for(j=1;j<=k;j++)
            {
                q.emplace(a[head[u][i]][j],w+1);
            }
        }
    }
    printf("-1");
}
