#include<bits/stdc++.h>
using namespace std;

int mat[23][23],n,jum[462200][22];
int dp(int bit,int idx)
{
    if(jum[bit][idx]>-1000000000)
        return jum[bit][idx];
    if(__builtin_popcount(bit)==n-2)
    {
        return mat[idx][n];
    }
    int i,j=1,mc=-1000000000;
    for(i=2;i<n;i++)
    {
        if((bit|j)!=bit)
        {
            mc=max(mc,dp(bit|j,i)+mat[idx][i]);
        }
        j<<=1;
    }
    return jum[bit][idx]=mc;
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<262199;i++)
        for(j=0;j<=20;j++)
            jum[i][j]=-1000000000;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    if(n==1)
    {
        printf("0");return 0;
    }
    else if(n==2)
    {
        printf("%d",mat[1][n]);return 0;
    }
    j=1;
    int mc=-1000000000;
    for(i=2;i<n;i++)
    {
        mc=max(mc,dp(j,i)+mat[1][i]);
        j<<=1;
    }
    printf("%d",mc);
}
