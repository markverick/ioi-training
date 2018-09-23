#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
pair<int,int> p[100135];
int hsh[333][333],jum[333][333];
int dp(int fst,int lst)
{
    if(jum[fst][lst]>=0)
        return jum[fst][lst];
    int i,mc=0;
    if(fst==lst)
        return hsh[fst][lst];
    for(i=fst;i<lst;i++)
    {
        mc=max(mc,dp(fst,i)+dp(i+1,lst)+hsh[fst][i]+hsh[i+1][lst]);
    }
    return jum[fst][lst]=mc;
}
int main()
{
    int i,j,k,n,m,a,b;
    memset(jum,-1,sizeof jum);
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        hsh[a][b]++;
    }
    printf("%d\n",m-dp(1,n));
}
