#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back
#define MI 1000000000
using namespace std;
int kp[5000135][3];
int main()
{
    freopen("feast.in","r",stdin);
    freopen("feast.out","w",stdout);

    int i,j,k,n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    kp[0][0]=1;
    for(i=0;i<=n;i++)
    {
        if(kp[i][0]==0)
            continue;
        if(i+a<=n)
            kp[i+a][0]=1;
        if(i+b<=n)
            kp[i+b][0]=1;
    }
//    for(i=0;i<=n;i++)
//        printf("%d",kp[i][0]);
//    printf("\n");
    for(i=0;i<=n;i++)
    {
        if(kp[i][0]==1)
            kp[i/2][1]=1;
    }
    for(i=0;i<=n;i++)
    {
        if(kp[i][0]==0)
            continue;
        if(i+a<=n)
            kp[i+a][1]=1;
        if(i+b<=n)
            kp[i+b][1]=1;
        kp[i][1]=1;
    }
    for(i=0;i<=n;i++)
    {
        if(kp[i][1]==0)
            continue;
        if(i+a<=n)
            kp[i+a][1]=1;
        if(i+b<=n)
            kp[i+b][1]=1;
    }

//    for(i=0;i<=n;i++)
//        printf("%d",kp[i][1]);
//    printf("\n");

    int mc=0;
    for(i=n;i>=0;i--)
    {
        if(kp[i][1]==1)
        {
            mc=i;break;
        }
    }
    for(i=n;i>=0;i--)
    {
        if(kp[i][0]==1)
        {
            mc=max(mc,i);break;
        }
    }
    printf("%d",mc);
}
