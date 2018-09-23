#include<bits/stdc++.h>
#define c1 x1,y1,x2-1,y2-1
#define c2 x2-1,y2-1,x2,y2
#define c3 x1,y2-1,x2-1,y2
#define c4 x2-1,y1,x2,y2-1
using namespace std;
char a[531][531];
int qs[531][531];
int bi,n;
int quick(int x1,int y1,int x2,int y2)
{
    int one=qs[1<<(x2-1)][1<<(y2-1)]-qs[1<<(x1-1)-1][1<<(y2-1)]-qs[1<<(x2-1)][1<<(y1-1)-1]+qs[1<<(x1-1)-1][1<<(y1-1)-1];
    return min(one,(1<<(x2-x1) )-one );
}
int dp(int x1,int y1,int x2,int y2)
{
    if(x1==x2&&y1==y2)
    {
        return 0;
    }
    printf("%d %d %d %d\n",x1,y1,x2,y2);
    int mn=1000000000;
    mn=min(mn,dp(c1)+dp(c2)
           +quick(c3)+quick(c4));
    mn=min(mn,dp(c1)+dp(c3)
           +quick(c2)+quick(c4));
    mn=min(mn,dp(c1)+dp(c4)
           +quick(c2)+quick(c4));
    mn=min(mn,dp(c2)+dp(c3)
           +quick(c1)+quick(c4));
    mn=min(mn,dp(c2)+dp(c4)
           +quick(c1)+quick(c3));
    mn=min(mn,dp(c3)+dp(c4)
           +quick(c1)+quick(c2));
    return mn;
}
int main()
{
    int i,j,k,tmp;bi=0;
    scanf("%d",&n);
    tmp=n;
    while(tmp>0)
    {
        tmp/=2;bi++;
    }
    bi--;
    //printf("%d\n",bi);
    for(i=1;i<=n;i++)
    {
        scanf("%s",a[i]+1);
        for(j=1;j<=n;j++)
        {
            a[i][j]-='0';
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    printf("%d",dp(1,1,bi,bi));
}
