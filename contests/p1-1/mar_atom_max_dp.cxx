#include<bits/stdc++.h>
using namespace std;
int a[531];
int jum[531][531];
inline int dp(int fst,int lst)
{
    if(jum[fst][lst]>=0)
        return jum[fst][lst];
    int i,j;
    if(fst-1>=lst)
        return 0;
    if(fst+1==lst)
    {
        return jum[fst][lst]=abs(a[lst]-a[fst]);
    }
    int mc=0,tmp;
    for(i=fst;i<=lst;i+=2)
    {
        tmp=dp(fst,i-1);
        for(j=i+1;j<=lst;j+=2)
        {
            mc=max(mc,tmp+dp(i+1,j-1)+dp(j+1,lst)+abs(a[i]-a[j]));
        }
    }
    return jum[fst][lst]=mc;
}
int main()
{
    int n,i,j,k;
    memset(jum,-1,sizeof jum);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d",dp(1,n));
}
