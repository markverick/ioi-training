#include<bits/stdc++.h>
using namespace std;
int kp[2100];
int main()
{
    int T,t;
    scanf("%d",&T);
    int i,j,k;
    int n;
    //memset(kp,-1,sizeof kp);
    kp[0]=1;
    for(i=1;i<=2000;i++)
    {
        for(j=2000;j>=0;j--)
        {
            kp[j+i]+=kp[j];
            kp[j+i]%=100999;
        }
    }
    for(t=0;t<T;t++)
    {
        scanf("%d",&n);
        printf("%d\n",kp[n]);
    }
}
