#include<bits/stdc++.h>
using namespace std;
long long ncr[135][135];
int main()
{
    long long C,n,t,p,i,j;
    scanf("%lld",&C);
    ncr[0][0]=1;
    for(i=1;i<=75;i++)
    {
        ncr[i][0]=1;
        for(j=1;j<=75;j++)
            ncr[i][j]=ncr[i][j-1]*(i+1-j)/j;
    }
    while(C--)
    {
        scanf("%lld %lld %lld",&n,&t,&p);
        t-=n*p;t+=n-1;
        if(t<=0)
        {
            printf("0\n");
            continue;
        }
        //printf("%lld %lld\n",t,n-1);
        printf("%lld\n",ncr[t][n-1]);
    }
}
