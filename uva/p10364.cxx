#include<bits/stdc++.h>
using namespace std;
int a[35],all,n,m;
int jum[1200000];
int dp(int bit,int sum)
{
    if(jum[bit]>=0)
        return jum[bit];
    if(sum==all)
    {
        return 1;
    }
    //printf("%d %d\n",bit,sum);
    int mc=0,i;
    for(i=1;i<=m;i++)
    {
        if( bit!=(bit|(1<<(i-1))) )
        {
            if(sum<all/4&&sum+a[i]>=all/4)
            {
                if(sum+a[i]==all/4)
                    mc=max(mc,dp((bit|(1<<(i-1))),sum+a[i]) );
            }
            else if(sum<all/2&&sum+a[i]>=all/2)
            {
                if(sum+a[i]==all/2)
                    mc=max(mc,dp((bit|(1<<(i-1))),sum+a[i]) );
            }
            else if(sum<all*3/4&&sum+a[i]>=all*3/4)
            {
                if(sum+a[i]==all*3/4)
                    mc=max(mc,dp((bit|(1<<(i-1))),sum+a[i]) );
            }
            else if(sum<all&&sum+a[i]>=all)
            {
                if(sum+a[i]==all)
                    mc=max(mc,dp((bit|(1<<(i-1))),sum+a[i]) );
            }
            else
                mc=max(mc,dp((bit|(1<<(i-1))),sum+a[i]) );

        }
    }
    return jum[bit]=mc;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        all=0;
        scanf("%d",&m);
        memset(jum,-1,sizeof jum);
        for(j=1;j<=m;j++)
        {
            scanf("%d",&a[j]);
            all+=a[j];
        }
        if(all%4)
        {
            printf("no\n");
        }
        else
        {
            if(dp(0,0)==0)
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
