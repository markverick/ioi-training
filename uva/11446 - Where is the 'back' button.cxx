#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int d[30][30],p[30];
int hsh[30];
vector<int> adj[30];
int adg[30][30];
int Find(int x)
{
    if(x==p[x])return x;
    return p[x]=Find(p[x]);
}
int Union(int x,int y)
{
    x=Find(x);
    y=Find(y);
    p[x]=y;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,a,b,T;
	scanf("%d",&T);
	while(T--)
    {
        memset(adg,0,sizeof adg);
        memset(hsh,0,sizeof hsh);
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
            adj[i].clear();
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                d[i][j]=1;
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            adj[a].emplace_back(b);
            d[a][b]=0;
        }
        for(i=0;i<n;i++)
            d[i][i]=0,p[i]=i;
        for(k=0;k<n;k++)
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(d[i][j]==0&&d[j][i]==0&&Find(i)!=Find(j))
                    Union(i,j);
//                printf("%d",d[i][j]);
            }
//            printf("\n");
        }
        for(i=0;i<n;i++)
        {
            hsh[Find(i)]=1;
            for(j=0;j<adj[i].size();j++)
            {
                adg[Find(i)][Find(adj[i][j])]=1;
//                printf("%d -> %d\n",Find(i),Find((adj[i][j])));
            }
        }
        int sum=0;
        for(i=0;i<n;i++)
        {
            if(!hsh[i])continue;
            for(j=0;j<n;j++)
            {
                if(!hsh[j]||i==j)continue;
                sum+=2-adg[i][j]-adg[j][i];
            }
        }
        printf("%d\n",sum);
    }
}
