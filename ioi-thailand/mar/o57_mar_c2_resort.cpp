#include<bits/stdc++.h>
using namespace std;
int maps[1135][1135],qs[1135][1135];
int quick(int a,int b,int c,int d)
{
    return qs[c][d]-qs[c][b-1]-qs[a-1][d]+qs[a-1][b-1];
}
int main()
{
    int n,m,t,i,j,k,a,b;
    scanf("%d %d %d",&n,&m,&t);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        a++;b++;
        maps[a][b]=1;
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        {
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+maps[i][j];
        }
    }
    int fst=0,mid,lst=1000000,h,fu=0,mn=1000000000;
    while(fst<=lst)
    {
        fu=0;
        mid=(fst+lst)/2;
        for(i=1;i<=m;i++)
        {
            for(j=i;j<=m;j++)
            {
                h=mid/(j-i+1);
                if(h>=m)
                    h=m;
                if(quick(1,i,h,j)>=t)
                {
                    fu=1;
                    break;
                }
            }
            if(fu==1)
                break;
        }
        if(fu==0)
        {
            fst=mid+1;
        }
        else
        {
            lst=mid-1;
            mn=min(mn,mid);
        }
    }
    printf("%d",mn);
}
