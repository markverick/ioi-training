#include<bits/stdc++.h>
using namespace std;
int h[10135],n;
int jum[10135][5];
inline int dp(int idx,int jet)
{
    if(jum[idx][jet]>=0)
        return jum[idx][jet];
    if(idx==n)
    {
        return 0;
    }
    int i,mc=0;
    for(i=idx+1;i<=n;i++)
    {
        if(h[i]<h[idx])
        {
            mc=max(mc,dp(i,jet)+1);
        }
        else if(jet<3)
            mc=max(mc,dp(i,jet+1)+1);
    }
    return jum[idx][jet]=mc;
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    memset(jum,-1,sizeof jum);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
    }
    printf("%d",dp(0,0));
}
