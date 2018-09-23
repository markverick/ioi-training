#include<bits/stdc++.h>
using namespace std;
int l,n;
int a[135];
int jum[1135][1135];
int dp(int fst,int lst)
{
    if(jum[fst][lst]>=0)
        return jum[fst][lst];
    if(fst+1==lst)
    {
        return 0;
    }
    int mn=1000000000;
    for(int i=fst+1;i<lst;i++)
    {
        mn=min(mn,dp(fst,i)+dp(i,lst)+a[lst]-a[fst]);
    }
    return jum[fst][lst]=mn;
}
int main()
{
    int T,i,j,k;
    while(scanf("%d",&l)!=EOF)
    {
        if(l==0)
            return 0;
            memset(jum,-1,sizeof jum);
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        a[n+1]=l;
        printf("The minimum cutting is %d.\n",dp(0,n+1));
    }
}
