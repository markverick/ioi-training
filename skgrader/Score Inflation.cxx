#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int kp[10135];
int main()
{
    int n,T,i,j,k,a,b;
    scanf("%d %d",&T,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        for(j=b;j<=T;j++)
        {
            kp[j]=max(kp[j],kp[j-b]+a);
        }
    }
    int mc=0;
    for(i=T;i>=0;i--)
    {
        mc=max(mc,kp[i]);
    }
    printf("%d",mc);


}
