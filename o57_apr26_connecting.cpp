#include<bits/stdc++.h>
#define X first
#define MP make_pair
#define Y second
using namespace std;
vector<pair<long long,long long> > vec[6];
vector<pair<long long,long long> > ::iterator it;
vector<tuple<long long,long long,long long> > v;
long long x[100135],y[100135],p[100135],hi[100135];
long long Pow(long long z)
{
    return z*z;
}
long long Find(long long idx)
{
    while(p[idx]!=idx)
    {
        idx=p[idx];
    }
    return idx;
}
void Union(long long x,long long y)
{
    x=Find(x);
    y=Find(y);
    if(hi[x]>=hi[y])
    {
        p[y]=x;
        hi[x]=max(hi[x],hi[y]+1);
    }
    else
    {
        p[x]=y;
        hi[y]=max(hi[y],hi[x]+1);
    }
}
long long dist(long long a,long long b)
{
    return Pow(x[a]-x[b])+Pow(y[a]-y[b]);
}
tuple<long long,long long,long long> mt(long long a,long long b)
{
    return make_tuple(dist(a,b),a,b);
}
int main()
{
    long long i,j,k,n,w,h,f=0,a,b,wi;
    scanf("%lld %lld %lld",&n,&w,&h);
    for(i=1;i<=n;i++)
    {
        p[i]=i;
        scanf("%lld %lld",&x[i],&y[i]);
        if(x[i]==0)
            vec[0].emplace_back(y[i],i);
        if(y[i]==0)
            vec[1].emplace_back(x[i],i);
        if(x[i]==w)
            vec[2].emplace_back(y[i],i);
        if(y[i]==h)
            vec[3].emplace_back(x[i],i);
        if(x[i]!=0&&x[i]!=w&&y[i]!=0&&y[i]!=h)
            f=i;
    }
    sort(vec[0].begin(),vec[0].end());
    sort(vec[1].begin(),vec[1].end());
    sort(vec[2].begin(),vec[2].end());
    sort(vec[3].begin(),vec[3].end());
    int tmp;
    for(i=0;i<vec[0].size();i++)
    {
        if(vec[2].empty())
            continue;
        tmp=lower_bound(vec[2].begin(),vec[2].end(),MP(vec[0][i].X,0ll))-vec[2].begin();
        if(tmp<vec[2].size());
            v.emplace_back(mt(vec[0][i].Y,vec[2][tmp].Y));
        if(tmp>0)
        {
            tmp--;
            v.emplace_back(mt(vec[0][i].Y,vec[2][tmp].Y));
        }
    }
    for(i=0;i<vec[1].size();i++)
    {
        if(vec[3].empty())
            continue;
        tmp=lower_bound(vec[3].begin(),vec[3].end(),MP(vec[1][i].X,0ll))-vec[3].begin();
        if(tmp<vec[3].size())
            v.emplace_back(mt(vec[1][i].Y,vec[3][tmp].Y));
        if(tmp>0)
        {
            tmp--;
            v.emplace_back(mt(vec[1][i].Y,vec[3][tmp].Y));
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<(long long)vec[i].size()-1;j++)
        {
            v.emplace_back(Pow(vec[i][j+1].X-vec[i][j].X),vec[i][j].Y,vec[i][j+1].Y);
        }
    }
//    for(i=0;i<(long long)vec[0].size()-1;i++)
//        v.emplace_back(Pow(vec[0][i+1].X-vec[0][i].X),vec[0][i].Y,vec[0][i+1].Y);
//    for(i=0;i<(long long)vec[1].size()-1;i++)
//        v.emplace_back(Pow(vec[1][i+1].X-vec[1][i].X),vec[1][i].Y,vec[1][i+1].Y);
//    for(i=0;i<(long long)vec[2].size()-1;i++)
//        v.emplace_back(Pow(vec[2][i+1].X-vec[2][i].X),vec[2][i].Y,vec[2][i+1].Y);
//    for(i=0;i<(long long)vec[3].size()-1;i++)
//        v.emplace_back(Pow(vec[3][i+1].X-vec[3][i].X),vec[3][i].Y,vec[3][i+1].Y);
    if(f>0)
    {
        for(i=0;i<vec[0].size();i++)
        {
            v.emplace_back(Pow(x[f])+Pow(y[f]-vec[0][i].X),vec[0][i].Y,f);
        }
        for(i=0;i<vec[1].size();i++)
        {
            v.emplace_back(Pow(x[f]-vec[1][i].X)+Pow(y[f]),vec[1][i].Y,f);
        }
        for(i=0;i<vec[2].size();i++)
        {
            v.emplace_back(Pow(w-x[f])+Pow(y[f]-vec[2][i].X),vec[2][i].Y,f);
        }
        for(i=0;i<vec[3].size();i++)
        {
            v.emplace_back(Pow(x[f]-vec[3][i].X)+Pow(h-y[f]),vec[3][i].Y,f);
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i==j)continue;
            if(vec[i].empty()||vec[j].empty())continue;
            v.emplace_back(mt(vec[i][0].Y,vec[j][0].Y));
            v.emplace_back(mt(vec[i][vec[i].size()-1].Y,vec[j][0].Y));
            v.emplace_back(mt(vec[i][0].Y,vec[j][vec[j].size()-1].Y));
            v.emplace_back(mt(vec[i][vec[i].size()-1].Y,vec[j][vec[j].size()-1].Y));
        }
    }
    sort(v.begin(),v.end());
    long long sum=0;
    for(i=0;i<v.size();i++)
    {
        tie(wi,a,b)=v[i];
        if(Find(a)!=Find(b))
        {
            sum+=wi;
            Union(a,b);
        }
    }
    printf("%lld",sum);
}
