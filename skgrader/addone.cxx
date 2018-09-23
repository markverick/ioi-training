#include<bits/stdc++.h>
using namespace std;
int n,a[100135];
int dp[2][10135];
vector<int> v;
int main()
{
    int i,j,k,l,st,ed,st2,ed2;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    if(a[1]>0||a[n]>0)
    {
        printf("0");
        return 0;
    }
    a[1]=0;a[n]=0;
    for(i=1;i<=n;i++)
    {
        if(a[i]>=0)
        {
            v.emplace_back(i);
        }
    }
    k=0;
    dp[1][a[1]]=1;
    for(i=1;i<n;i++)
    {
        l=i%2;
//        printf("%d %d %d\n",i,k,v[k+1]);
        memset(dp[l^1],0,sizeof dp[l^1]);
        if(i==v[k+1])
        {
            k++;
            st2=max(0,max(a[v[k]]-(i+1-v[k]),a[v[k+1]]-(v[k+1]-i-1)));
            ed2=max(0,min(a[v[k]]+(i+1-v[k]),a[v[k+1]]+(v[k+1]-i-1)));
//            printf("F\n");
            if(a[v[k]]+1<=ed2)
            {
                dp[l^1][a[v[k]]+1]+=dp[l][a[v[k]]];
                dp[l^1][a[v[k]]+1]%=1000000007;
            }
            if(a[v[k]]-1>=st2)
            {
                dp[l^1][a[v[k]]-1]+=dp[l][a[v[k]]];
                dp[l^1][a[v[k]]-1]%=1000000007;
            }
            if(a[v[k]]>=st2&&a[v[k]]<=ed2)
                dp[l^1][a[v[k]]]+=dp[l][a[v[k]]];;
                dp[l^1][a[v[k]]]%=1000000007;
        }
        else
        {
            st=max(0,max(a[v[k]]-(i-v[k]),a[v[k+1]]-(v[k+1]-i)));
            ed=max(0,min(a[v[k]]+(i-v[k]),a[v[k+1]]+(v[k+1]-i)));
            st2=max(0,max(a[v[k]]-(i+1-v[k]),a[v[k+1]]-(v[k+1]-i-1)));
            ed2=max(0,min(a[v[k]]+(i+1-v[k]),a[v[k+1]]+(v[k+1]-i-1)));
            for(j=st;j<=ed;j++)
            {
                if(j+1<=ed2)
                {
                    dp[l^1][j+1]+=dp[l][j];
                    dp[l^1][j+1]%=1000000007;
                }
                if(j-1>=st2)
                {
                    dp[l^1][j-1]+=dp[l][j];
                    dp[l^1][j-1]%=1000000007;
                }
                if(j>=st2&&j<=ed2)
                {
                    dp[l^1][j]+=dp[l][j];
                    dp[l^1][j]%=1000000007;
                }
            }
        }
    }
    printf("%d",dp[n%2][a[n]]);
}
