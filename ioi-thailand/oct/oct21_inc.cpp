#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int a[1135],st;
pair<int,int> dp[1135],mc;
//unordered_map<int,int> hsh;
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    mc.Y=-100000005;
    a[0]=-100000005;
    for(i=1;i<=n;i++)
    {
        for(j=i-1;j>=0;j--)
        {
            if(a[i]>a[j])
            {
                if(dp[j].X+1>=dp[i].X)
                {
                    dp[i].Y=j;
                    dp[i].X=dp[j].X+1;
                }
            }
            if(mc.X<=dp[i].X)
            {
                mc=make_pair(dp[i].X,dp[i].Y);
                st=i;
            }
        }
    }
    printf("%d\n",mc.X);
    int idx=mc.Y;
    stack<int> out;
    out.emplace(a[st]);
    while(idx!=0)
    {
        out.emplace(a[idx]);
        idx=dp[idx].Y;
    }
    while(!out.empty())
    {
        printf("%d ",out.top());out.pop();
    }
}
