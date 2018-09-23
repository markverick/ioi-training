#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int ship[105][105],nw[105];
vector<pair<int,int> > vec[105];
queue<int > q;
int main()
{
    int n,m,i,j,ct,p,s,x;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            scanf("%d",&x);
            if(x!=0)
            {
                ship[i][x]=j;
                vec[x].push_back(make_pair(j,i));
            }
        }
    for(i=1;i<=n;i++)
    {
        sort(vec[i].begin(),vec[i].end());
        q.push(i);
    }
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        if(vec[p].size()==0) continue;
        s=vec[p].back().Y;
        vec[p].pop_back();
        if(nw[s]==0||ship[s][nw[s]]>ship[s][p])
        {
            if(nw[s]!=0) q.push(nw[s]);
            nw[s]=p;
        }
        else q.push(p);
    }

    for(i=1;i<=n;i++)
        printf("%d\n",ship[i][nw[i]]);


}
