#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
int a[222],jum[222][222][222],hsh[222],n;
vector<pair<int,int> > v;
int Pow(int x)
{
    return x*x;
}
int dp(int fst,int lst,int col)
{
    if(fst>lst)
        return 0;
    if(jum[fst][lst][col]>=0)
        return jum[fst][lst][col];
    int mc,i;
    if(fst==lst)
    {
        return Pow(col+v[fst].Y);
    }
//    printf("%d %d %d\n",fst,lst,col);
    if(fst+1<=lst)
        mc=dp(fst+1,lst,0)+Pow(col+v[fst].Y);
    else
        mc=Pow(col+v[fst].Y);
    for(i=fst+1;i<=lst;i++)
    {
        if(v[i].X==v[fst].X)
        {
            if(fst+1<=lst&&fst+1<=i-1)
                mc=max(mc,dp(fst+1,i-1,0)+dp(i,lst,col+v[fst].Y));
            else
                mc=max(mc,dp(i,lst,col+v[i].Y));
        }
    }
    return jum[fst][lst][col]=mc;
}
int main()
{
    int i,j,k,T,t=0;
    scanf("%d",&T);
    while(T--)
    {
        memset(jum,-1,sizeof jum);
        memset(hsh,0,sizeof hsh);
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
        printf("Case %d: %d\n",t,dp(0,v.size()-1,0));
    }
}
