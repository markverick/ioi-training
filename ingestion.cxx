#include<bits/stdc++.h>
using namespace std;
int n,A;
int x[135];
//int jum[135][1000000135]
int dp(int idx,int mass)
{
    if(idx==n)
    {
        return 0;
    }
    int i;
    //printf("%d %d\n",idx,mass);
    //system("pause");
    for(i=idx+1;i<=n;i++)
    {
        if(mass>x[i])
        {
            mass+=x[i];
        }
        else
        {
            break;
        }
    }
    idx=i-1;
    int mn=n-idx;
    if(mass>1)
        mn=min(mn,dp(idx,mass*2-1)+1);
    return mn;
}
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&A,&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x[i]);
        }
        sort(&x[0],&x[n+1]);
        printf("%d\n",dp(0,A));
    }
}
