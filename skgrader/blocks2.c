#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
int a[222],jum[222][222];
vector<pair<int,int> > v;
int Pow(int x)
{
    return x*x;
}
int dp(int fst,int lst)
{
    if(jum[fst][lst]>=0)
        return jum[fst][lst];
    int i,j,k,mc=0;
    if(fst==lst)
    {
        return Pow(v[fst].Y);
    }
    if(v[fst].X==v[lst].X)
    {
        mc=max(mc,dp(fst+1,lst-1)+Pow(v[fst].Y+v[lst].Y));
    }
    for(i=fst;i<lst;i++)
    {
        mc=max(mc,dp(fst,i)+dp(i+1,lst));
    }
    return jum[fst][lst]=mc;
}
int main()
{
    int i,j,k,T,n,t=0;
    scanf("%d",&T);
    while(T--)
    {
        memset(jum,-1,sizeof jum);
        t++;
        v.clear();
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        v.emplace_back(a[1],1);
        for(i=2;i<=n;i++)
        {
            if(a[i]==a[i-1])
            {
                v[v.size()-1].Y++;
            }
            else
            {
                v.emplace_back(a[i],1);
            }
        }
        printf("Case %d: %d\n",t,dp(0,v.size()-1));
    }
}
