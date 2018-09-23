#include<bits/stdc++.h>
using namespace std;
int a[135],qs[135],n,jum[135][135][3];
int dp(int fst,int lst,int turn)
{
    if(jum[fst][lst][turn]>-2000000000)
        return jum[fst][lst][turn];
    if(fst>lst)
    {
        return 0;
    }
    int mc=-2000000000,idx,i;
    for(i=fst+1;i<=lst+1;i++)
    {
        if(turn==1)
            mc=max(mc,dp(i,lst,1-turn)+qs[i-1]-qs[fst-1]);
        else
            mc=max(mc,-dp(i,lst,1-turn)+qs[i-1]-qs[fst-1]);
    }
    for(i=lst-1;i>=fst-1;i--)
    {
        if(turn==1)
            mc=max(mc,dp(fst,i,1-turn)+qs[lst]-qs[i]);
        else
            mc=max(mc,-dp(fst,i,1-turn)+qs[lst]-qs[i]);
    }
    if(turn==0)
        return jum[fst][lst][turn]=-mc;
    else
        return jum[fst][lst][turn]=mc;
}
int main()
{
    int i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<=101;i++)
            for(j=0;j<=101;j++)
                for(k=0;k<=1;k++)
                    jum[i][j][k]=-2000000000;
//        memset(a,-1,sizeof a);
//        memset(qs,-1,sizeof qs);
        if(n==0)
            return 0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            qs[i]=qs[i-1]+a[i];
        }
        printf("%d\n",dp(1,n,1));
    }
}
