#include<bits/stdc++.h>
int n,m,a[2000];
int res[2000];
int chk=0;
void fx(int idx)
{
    int i;
    int sum=0;
    if(chk==1)return;
    if(idx==n)
    {
        for(i=0;i<n;i++)
        {
            if(res[i]==1)
            sum+=a[i];
        }
        //printf("%d",sum);
        if(sum==m)
        {
            chk=1;
        }
        sum=0;
        return;
    }
    res[idx]=0;
    fx(idx+1);
    res[idx]=1;
    fx(idx+1);
}
int main()
{
    int t;
    scanf("%d",&t);
    int i,j,k;
    for(i=1;i<=t;i++)
    {
        memset(a,0,sizeof a);
        memset(res,0,sizeof res);
        chk=0;
        scanf("%d %d",&n,&m);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        fx(0);
        if(chk==1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}
