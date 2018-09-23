#include<bits/stdc++.h>
#define EPS 0.000001
#define X first
#define Y second
#define MP make_pair
using namespace std;
double m[12],c[12];
int vert[12],id[12][50135];
vector<pair<int,int> > p[12];
pair<int,int> point[50135];
vector<tuple<int,int,int> > v;
int dist(int x,int y)
{
    return x*x+y*y;
}
int dist2(pair<int,int> a,pair<int,int> b)
{
    return (a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y);
}
tuple<int,int,int> mt(int a,int b)
{
    return make_tuple(dist2(point[a],point[b]),a,b);
}
int Find(int idx)
{
    while(P[idx]!=idx)
    {
        idx=P[idx];
    }
    return idx;
}
void Union(int x,int y)
{
    x=Find(x);
    y=Find(y);
    if(h[x]>=h[y])
    {
        P[y]=x;
        h[x]=max(h[x],h[y]+1);
    }
    else
    {
        P[x]=y;
        h[y]=max(h[y],h[x]+1);
    }
}
int main()
{
    int n,m,i,j,k,a,b,c,lai=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        p[i]=i;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&c);
        for(j=1;j<=c;j++)
        {
            scanf("%d %d",&a,&b);
            p[i].emplace_back(a,b);
        }
        sort(p[i].begin(),p[i].end());
    }
    for(i=1;i<=m;i++)
    {
        for(j=0;j<p[i].size();j++)
        {
            lai++;
            id[i][j]=lai;
            point[lai]=p[i][j];
        }
    }
    for(i=1;i<=m;i++)
    {
        if(abs(p[i][0].X-p[i][1].X)<=EPS)
        {
            vert[i]=1;
        }
        else
        {
            m=(p[i][1].Y-p[i][0].Y)/(p[i][1].X-p[i][0].X);
            c=-m*p[i][0].X+p[i][0].Y;
        }
    }
    pair<int,int> u;
    int tmp,fst,lst,x,y;
    for(i=0;i<lai;i++)
    {
        u=p[i][j];
        for(k=1;k<=m;k++)
        {
            if(vert[k])
            {
                tmp=lower_bound(p[k].begin(),p[k].end(),make_pair(u.X,0))-p[k].begin();
                if(tmp<p[k].size())
                    v.emplace_back(mt(i,id[k][tmp]));
                if(tmp>0)
                    tmp--,v.emplace_back(mt(i,id[k][tmp]));
            }
            fst=0;lst=p[k].size()-1;
            while(fst+1<lst)
            {
                a=fst+(lst-fst+1)/3;
                b=lst-(lst-fst+1)/3;
                x=dist2(u,p[k][a]);
                y=dist2(u,p[k][b]);
                if(x<=y)
                {
                    lst=b;
                }
                else
                {
                    fst=a;
                }
            }
            v.emplace_back(mt(i,id[k][fst]));
            v.emplace_back(mt(i,id[k][fst+1]));
            v.emplace_back(mt(i,id[k][lst]));
            v.emplace_back(mt(i,id[k][lst+1]));
        }
    }
    int w;
    sort(v.begin(),v.end());
    for(i=0;i<v.size();i++)
    {
        tie(w,a,b)=v[i];
        if(Find(a)!=Find(b))
        {
            Union(a,b);
            sum+=w;
        }
    }
}
