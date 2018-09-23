#include<bits/stdc++.h>
using namespace std;
int a[35],sum,n,m;
int dp(int bit,int cot)
{
    if(__builtin_popcount(bit)==m)
    {
        return 1;
    }
    void
    for(i=1;i<=m;i++)
    {
        if(bit|(1<<(i-1)))!=bit)
    }
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&m);
        for(j=1;j<=m;j++)
        {
            scanf("%d",&a[j]);
            sum+=a[j];
        }
        if(sum%4)
        {
            printf("no\n");
        }
        else
        {
            if(dp(0)==0)
            {
                printf("no\n");
            }
            else
            {
                printf("yes\n");
            }
        }
    }
}
