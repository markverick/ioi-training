#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
int x[20135];
int y[20135];
int main()
{
    int n,i,j,k,xx,yy,zz;
    scanf("%d %d %d %d",&n,&xx,&yy,&zz);
    //int fst=1,lst=1;
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    sort(&x[1],&x[n+1]);
    sort(&y[1],&y[n+1]);
    x[n+1]=1000000000;
    y[n+1]=1000000000;
    int a=1,b=1;
    int sum=xx*n;
    int mc=0;
    while(a<=n||b<=n)
    {
        if(x[a]<=y[b])
        {
            a++;
            sum-=xx;
            sum+=yy;

        }
        else
        {
            b++;
            sum-=yy;
            sum+=zz;
        }
        mc=max(mc,sum);
    }
    printf("%d",mc);
}
