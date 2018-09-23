#include<bits/stdc++.h>
using namespace std;
int maps[111][111];
queue<pair<int,int> > q;
int main()
{
    int i,j,k,n,A,B,a,b,r,c,x,y;
    scanf("%d %d %d",&n,&r,&c);
    if(n%2==0)
    {
        A=n/2;B=n/2;
    }
    else
    {
        A=n/2+1;B=n/2;
    }
    k=0;
    a=1;b=2;
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            maps[i][j]=(i%2)^(j%2);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(maps[i][j]==0)
            {
                if(a/2<A)
                    maps[i][j]=a,a+=2;
                else
                    maps[i][j]=0;
            }
            else
            {
                if(b/2<=B)
                    maps[i][j]=b,b+=2;
                else
                    maps[i][j]=0;
            }
        }
    }
    if(a/2>=A&&b/2>=B)
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            printf("%d ",maps[i][j]);
        }
        printf("\n");
    }
    else
        printf("-1");
}
