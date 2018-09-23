#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
long long n,cost[50135];
pair<long long,long long> p[50135],st[50135];
double cross(pair<long long,long long> x,pair<long long,long long> y)
{
    double m1,m2,c1,c2;
    tie(m1,c1)=x;
    tie(m2,c2)=y;
    return (c1-c2)/(m2-m1);
}
long long bad(pair<long long,long long> x,pair<long long,long long> y,pair<long long,long long> z)
{
    return ((y.X-z.X) * (y.Y-x.Y) >= (x.X-y.X) * (z.Y-y.Y));
}
int main()
{
//    freopen("acquire.txt","r",stdin);
    long long i,j,k;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&p[i].X,&p[i].Y);
        p[i].X=-p[i].X;
    }
    sort(&p[1],&p[n+1]);
    long long mc=-1;
    vector<pair<long long,long long> > v;
    for(i=1;i<=n;i++)
    {
        if(p[i].Y>=mc)
        {
            mc=p[i].Y;
            v.emplace_back(-p[i].X,p[i].Y);
        }
    }
    sort(v.begin(),v.end());
//    prlong longf("%lld\n",v.size());
//    for(i=0;i<v.size();i++)
//    {
//        printf("!%lld %lld\n",v[i].X,v[i].Y);
//    }
    cost[0]=0;
    st[0]=make_pair(v[0].Y,0);
    long long tmp,fst=0,lst=1;
    for(i=0;i<v.size();i++)
    {
        for(j=fst;j<lst;j++)
        {
            tmp=st[j].X*v[i].X+st[j].Y;
//            printf("%lld %lld %lld\n",st[j].X,v[i].X,st[j].Y);
            if(j==fst)
                cost[i+1]=tmp;
            else if(tmp<cost[i+1])
            {
                cost[i+1]=tmp;
                fst=j;
            }
            else
            {
                break;
            }
        }
//        printf("#%lld\n",cost[i+1]);
        if(i<v.size()-1)
        {
            st[lst]=make_pair(v[i+1].Y,cost[i+1]);
            lst++;
        }
        while(lst-fst>=3&&bad(st[lst-3],st[lst-2],st[lst-1]))
        {
            st[lst-2]=st[lst-1];
            lst--;
        }
    }
    printf("%lld\n",cost[v.size()]);
}
