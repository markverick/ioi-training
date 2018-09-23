#include<bits/stdc++.h>
using namespace std;
int a[135][135];
int n,k;
int jum[135][135][10];
int dp(int x,int y,int neg)
{
    if(jum[x][y][neg]>-1000000005)
        return jum[x][y][neg];
    //printf("%d %d %d\n",x,y,neg);
    int i,mc=-1000000000,sum=0,tmp=neg;
    if(x==n)
    {
        if(y==n)
            return 0;
        else
            return -1000000000;
    }
    for(i=y;i<=n;i++)
    {
        if(a[x+1][i]<0)
        {
            if(tmp+1<=k)
            {
                tmp++;
            }
            else
            {
                break;
            }
        }
        sum+=a[x+1][i];
        mc=max(mc,dp(x+1,i,tmp)+sum);
    }
    tmp=neg;sum=0;
    for(i=y;i>=1;i--)
    {
        if(a[x+1][i]<0)
        {
            if(tmp+1<=k)
            {
                tmp++;
            }
            else
            {
                break;
            }
        }
        sum+=a[x+1][i];
        if(i!=y)
            mc=max(mc,dp(x+1,i,tmp)+sum);
    }
    //printf("=%d\n",mc);
    return jum[x][y][neg]=mc;
}
int main()
{
    int i,j,tmp,T=0,l;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        T++;
        for(i=0;i<=100;i++)
        {
            for(j=0;j<=100;j++)
            {
                for(l=0;l<=7;l++)
                {
                    jum[i][j][l]=-1000000005;
                }
            }
        }
        if(n==0&&k==0)
            return 0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        tmp=dp(0,1,0);
        printf("Case %d: ",T);
        if(tmp<-500000000)
        {
            printf("impossible\n");
        }
        else
        {
            printf("%d\n",tmp);
        }
    }
}
