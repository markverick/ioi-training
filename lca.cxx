#include<bits/stdc++.h>
using namespace std;
int c[3000],a[3000];
int teema[3000];
int sp[3000][23];
vector<int> adj[3000];
vector<int> v,hi;
void dfs(int idx,int h)
{
    for(int i=0;i<adj[idx].size();i++)
    {
        v.emplace_back(adj[idx][i]);
        hi.emplace_back(h+1);
        dfs(adj[idx][i],h+1);
        v.emplace_back(idx);
        hi.emplace_back(h);
    }
}
int main()
{
    int n,i,j,k,m,x,y,T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        v.clear();hi.clear();
        printf("Case %d:\n",t++);
        memset(teema,0,sizeof teema);
        memset(sp,0,sizeof sp);
//        memset(h,0,sizeof h);
        for(i=0;i<=1005;i++)
        {
            adj[i].clear();
        }
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&c[i]);
            for(j=1;j<=c[i];j++)
            {
                scanf("%d",&a[i]);
                adj[i].emplace_back(a[i]);
            }
        }
        v.emplace_back(1);
        hi.emplace_back(0);
        dfs(1,0);
        for(i=0;i<v.size();i++)
        {
            teema[v[i]]=i;
        }
        for(i=0;i<hi.size();i++)
            sp[i][0]=i;
        for(j=1;(1<<j)<=hi.size();j++)
        {
            for(i=0;i+(1<<j)<=hi.size();i++)
            {
                if(hi[sp[i][j-1]]<hi[sp[i+(1<<(j-1))][j-1]])
                    sp[i][j]=sp[i][j-1];
                else
                    sp[i][j]=sp[i+(1<<(j-1))][j-1];
            }
        }
//        for(i=0;i<v.size();i++)
//            printf("%d ",v[i]);
//        printf("\n");
//        for(i=0;i<v.size();i++)
//            printf("%d ",hi[i]);
        scanf("%d",&m);
        int tmp;
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&x,&y);
            x=teema[x];y=teema[y];
            if(x>y)
            {
                tmp=x;x=y;y=tmp;
            }
            //printf("%d %d\n",x,y);
            int sz=(int)floor(log2(y-x+1));
            if(hi[sp[x][sz]]<hi[sp[y-(1<<(sz))+1][sz]])
                printf("%d\n",v[sp[x][sz]]);
            else
                printf("%d\n",v[sp[y-(1<<(sz))+1][sz]]);
        }
    }
}

