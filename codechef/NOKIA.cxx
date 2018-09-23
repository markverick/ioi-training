#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n,m;
pair<int,int> jum[33][33];
pair<int,int> dp(int x,int y)
{
    if(jum[x][y].Y<1000000000)
        return jum[x][y];
    int i,j;
    if(x+1>=y)
    {
        return jum[x][y]=make_pair(0,0);
    }
    int mc=0,mn=1000000000;
    pair<int,int> a,b;
    for(i=x+1;i<y;i++)
    {
        a=dp(x,i);b=dp(i,y);
        mc=max(mc,a.Y+b.Y+y-x);
        mn=min(mn,a.X+b.X+y-x);
    }
    return jum[x][y]=make_pair(mn,mc);
}
int main()
{
    int i,j,k,T,fk,mn,mc;
    scanf("%d",&T);
    for(i=0;i<=32;i++)
        for(j=0;j<=32;j++)
            jum[i][j]=make_pair(0,1000000000);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        tie(mn,mc)=dp(0,n+1);
//        printf("=%d %d\n",mn,mc);
        if(m<mn)
            printf("-1\n");
        else if(m<=mc)
            printf("0\n");
        else
            printf("%d\n",m-mc);
    }
}
