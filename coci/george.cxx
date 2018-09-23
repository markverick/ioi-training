#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int G[1135],s,t,g,n,m,mat[1135][1135],ge[1135],d[1135];
vector<pair<int,int> > adj[1135];
priority_queue<pair<int,int> > pq;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,a,b,c,w,u;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            mat[i][j]=1000000000;
    for(i=1;i<=n;i++)
        d[i]=1000000000;
	scanf("%d %d %d %d",&s,&t,&k,&g);
	for(i=1;i<=g;i++)
    {
        scanf("%d",&G[i]);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
        mat[a][b]=c;
        mat[b][a]=c;
    }
    ge[0]=-k;
    for(i=1;i<=g;i++)
    {
        ge[i]=ge[i-1]+mat[G[i]][G[i-1]];
//        printf("! %d\n",ge[i]);
    }
    pq.emplace(0,s);
    d[s]=0;
    int tmp,id;
    while(!pq.empty())
    {
        tie(w,u)=pq.top();
        w=-w;
        pq.pop();
        j=-k;
        tmp=0;id=g;
        for(i=g-1;i>=1;i--)
        {
            if(ge[i]<=w)
            {
                tmp=max(0,mat[G[i]][G[i+1]]-(w-ge[i]));
                id=i;
                break;
            }
        }
//        printf("%d [%d] -> %d %d\n",u,w,tmp,id);
        for(i=1;i<=n;i++)
        {
//            printf("%d -> %d\n",u,i);
            if( (u==G[id]&&i==G[id+1]) || (u==G[id+1]&&i==G[id]) )
            {
//                printf("F");
                if(w+mat[u][i]+tmp<d[i])
                {
                    d[i]=w+mat[u][i]+tmp;
                    pq.emplace(-d[i],i);
                }
            }
            else
            {
                if(w+mat[u][i]<d[i])
                {
                    d[i]=w+mat[u][i];
                    pq.emplace(-d[i],i);
                }
            }
        }
    }
    printf("%d",d[t]);
}
