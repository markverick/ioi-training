#include<bits/stdc++.h>
#define c1 x,y,s-1
#define c2 x+(1<<(s-1)),y+(1<<(s-1)),s-1
#define c3 x,y+(1<<(s-1)),s-1
#define c4 x+(1<<(s-1)),y,s-1
using namespace std;
char a[531][531];
int qs[531][531];
int bi,n;
int jum[531][531][15];
int quick1(int x,int y,int s)
{
    int one=qs[x+(1<<s)-1][y+(1<<s)-1]-qs[x+(1<<s)-1][y-1]-qs[x-1][y+(1<<s)-1]+qs[x-1][y-1];
    return one;
}
int quick0(int x,int y,int s)
{
    int one=qs[x+(1<<s)-1][y+(1<<s)-1]-qs[x+(1<<s)-1][y-1]-qs[x-1][y+(1<<s)-1]+qs[x-1][y-1];
    return (1<<s)*(1<<s)-one;
}
int dp(int x,int y,int s)
{
    if(jum[x][y][s]>=0)
        return jum[x][y][s];
    if(s==0)
    {
        return 0;
    }
    int mn=1000000000;
    mn=min(mn,dp(c1)+dp(c2)+min(quick0(c3)+quick1(c4),quick1(c3)+quick0(c4)));
    mn=min(mn,dp(c1)+dp(c3)+min(quick0(c2)+quick1(c4),quick1(c2)+quick0(c4)));
    mn=min(mn,dp(c1)+dp(c4)+min(quick0(c2)+quick1(c3),quick1(c2)+quick0(c3)));
    mn=min(mn,dp(c2)+dp(c3)+min(quick0(c1)+quick1(c4),quick1(c1)+quick0(c4)));
    mn=min(mn,dp(c2)+dp(c4)+min(quick0(c1)+quick1(c3),quick1(c1)+quick0(c3)));
    mn=min(mn,dp(c3)+dp(c4)+min(quick0(c1)+quick1(c2),quick1(c1)+quick0(c2)));
    return jum[x][y][s]=mn;
}
int main()
{
    memset(jum,-1,sizeof jum);
    int i,j,k,tmp;bi=0;
    scanf("%d",&n);
    tmp=n;
    while(tmp>0)
    {
        tmp/=2;bi++;
    }
    bi--;
    for(i=1;i<=n;i++)
    {
        scanf("%s",a[i]+1);
        for(j=1;j<=n;j++)
        {
            a[i][j]-='0';
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+a[i][j];
        }
    }
    printf("%d",dp(1,1,bi));
}
