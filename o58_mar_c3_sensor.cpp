#include<bits/stdc++.h>
#define EPS 0.000001
#define X first
#define Y second
#define A point[a]
#define B point[b]
#define MP make_pair
using namespace std;
int vert[12],id[12][50135],P[50135],h[50135];
vector<pair<int,int> > p[12];
pair<int,int> point[50135];
vector<tuple<long long,int,int> > v;
inline long long dist2(pair<int,int> a,pair<int,int> b)
{
    long long c=a.X-b.X,d=a.Y-b.Y;
    return c*c+d*d;
}
inline tuple<long long,int,int> mt(int a,int b)
{
    long long c=A.X-B.X,d=A.Y-B.Y;
    return make_tuple(c*c+d*d,a,b);
}
inline int Find(int idx)
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
        P[i]=i;
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
    pair<int,int> u;
    int tmp,fst,lst,mid;
    long long x,y;
    for(i=1;i<=lai;i++)
    {
        u=point[i];
        for(k=1;k<=m;k++)
        {
            fst=0;lst=p[k].size()-1;
            while(lst-fst>2)
            {
                a=fst+(lst-fst)/3;
                b=lst-(lst-fst)/3;
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
            mid=(fst+lst)/2;
            if(mid>0&&i!=id[k][mid-1])
                v.emplace_back(mt(i,id[k][mid-1]));
            if(i!=id[k][mid])
                v.emplace_back(mt(i,id[k][mid]));
            if(mid+1<p[k].size()&&i!=id[k][mid+1])
                v.emplace_back(mt(i,id[k][mid+1]));
        }
    }

    long long w,sum=0;
    sort(v.begin(),v.end());
//    system("pause");
    for(i=0;i<v.size();i++)
    {
        tie(w,a,b)=v[i];
//        printf("%d %d %d\n",w,a,b);
        if(Find(a)!=Find(b))
        {
            Union(a,b);
            sum+=w;
        }
    }
    printf("%lld\n",sum);
}
