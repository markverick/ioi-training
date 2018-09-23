#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int x[55],y[55],z[55],a[55],b[55],c[55],t[55],d[55];
map<tuple<int,int,int>,int> id;
vector<tuple<int,int,int> > v;
vector<tuple<int,int,double> > adj[135];
tuple<int,int,int> st[55],ed[55],fst,lst;
priority_queue<pair<int,int> > pq;
double dis[135];
double dist(tuple<int,int,int> x,tuple<int,int,int> y)
{
    int sum=0;
    int a,b,c,d,e,f;
    tie(a,b,c)=x;
    tie(d,e,f)=y;
    return sqrt((a-d)*(a-d)+(b-e)*(b-e)+(c-f)*(c-f));
}
int main()
{
    int T,i,j,k,xs,ys,zs,xf,yf,zf,n,u,vv,lim;
    double ww,w;
    scanf("%d",&T);
    while(T--)
    {
        id.clear();
        v.clear();
        for(i=0;i<=130;i++)
        {
            adj[i].clear();
            dis[i]=1000000000;
        }
        scanf("%d %d %d %d %d %d",&xs,&ys,&zs,&xf,&yf,&zf);
        fst=tie(xs,ys,zs);
        lst=tie(xf,yf,zf);
//        printf("%d %d %d\n",xs,ys,zs);
        v.emplace_back(fst);
        v.emplace_back(lst);
        scanf("%d",&n);
//        x[0]=xs;y[0]=ys;z[0]=zs;
//        x[n+1]=xf;y[n+1]=yf;z[n+1]=zf;
        for(i=1;i<=n;i++)
        {
            scanf("%d %d %d %d %d %d %d %d",&x[i],&y[i],&z[i],&a[i],&b[i],&c[i],&t[i],&d[i]);
            st[i]=make_tuple(x[i],y[i],z[i]);
            ed[i]=make_tuple(a[i],b[i],c[i]);
            v.emplace_back(st[i]);
            v.emplace_back(ed[i]);
        }
        sort(v.begin(),v.end());
        auto it=unique(v.begin(),v.end());
        v.resize(distance(v.begin(),it));
        for(i=0;i<v.size();i++)
        {
            id[v[i]]=i;
        }
        for(i=0;i<v.size();i++)
        {
            for(j=0;j<v.size();j++)
            {
                adj[id[v[i]]].emplace_back(id[v[j]],-1000000000,dist(v[i],v[j]));
            }
        }
        for(i=1;i<=n;i++)
        {
            adj[id[st[i]]].emplace_back(id[ed[i]],t[i],d[i]);
        }
        dis[id[fst]]=0;
        pq.emplace(0,id[fst]);
        while(!pq.empty())
        {
            u=pq.top().Y;
            w=-pq.top().X;
            pq.pop();
            for(i=0;i<adj[u].size();i++)
            {
                tie(vv,lim,ww)=adj[u][i];
                if(w>=lim)
                {
                    if(ww+w<dis[vv])
                    {
                        dis[vv]=ww+w;
                        pq.emplace(-ww-w,vv);
                    }
                }
            }
        }
        printf("%d\n",(int)round(dis[id[lst]]));
    }
}
