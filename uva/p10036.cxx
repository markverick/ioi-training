#include<bits/stdc++.h>
using namespace std;
int a[10135],k,n;
int jum[10135][135];
int dp(int idx,int divis)
{
    if(jum[idx][divis]>=0)
        return jum[idx][divis];
    if(idx==n)
    {
        if(divis==0)
            return 1;
        else
            return 0;
    }
    return jum[idx][divis]=max(dp(idx+1,(divis+a[idx+1])%k ),dp(idx+1,(divis+k-a[idx+1])%k));
}
int main()
{
    int T,i;
    scanf("%d",&T);
    while(T--)
    {
        memset(jum,-1,sizeof jum);
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            a[i]=abs(a[i]);
            a[i]%=k;
        }
        if(dp(0,0)==1)
            printf("Divisible\n");
        else
            printf("Not divisible\n");
    }
}
