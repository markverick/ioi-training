#include<bits/stdc++.h>
#define MP(x,y,z) make_pair(x,make_pair(y,z))
#define PB push_back
using namespace std;
int n,m;
vector<pair<int,pair<int,int> > > adj[1200];
pair<int,int> dp(int x,int y)
{
    printf("[%d][%d]\n",x,y);
    if(x==n&&y==n)
    {
        return make_pair(0,0);
    }
    int mn=999999999;
    int mX=999999999;
    int mY=999999999;
    int i,j;

    for(i=0;i<adj[x].size();i++)
    {
        for(j=0;j<adj[y].size();j++)
        {
            int a = dp(adj[x][i].first,adj[y][j].first).first+adj[x][i].second.first;
            int b = dp(adj[x][i].first,adj[y][j].first).second+adj[x][i].second.second;
            printf("%d %d\n",a,b);
            if(x==1&&y==1)
            {
                if(a==b&&a<mn)
                {
                    mn=a;
                    mX=a;mY=b;
                }
            }
            else
            {
                if(max(a,b)<mn)
                {
                    mn=max(a,b);
                    mX=a;mY=b;
                }
            }
        }
    }
    return make_pair(mX,mY);
}
int main()
{
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        adj[a].PB(MP(b,c,d));
    }
    printf("%d",dp(1,1).first);
}
