#include<bits/stdc++.h>
using namespace std;
int ha[1000135];
int hb[1000135];
int main()
{
    long long n,x,y,a=0,b=0,c=0,d=0,i,j,sum=0;
    scanf("%lld %lld %lld",&n,&x,&y);
    for(i=0;i<n;i++)
    {
        ha[i]=1-(i/x)%2;
        hb[i]=1-(i/y)%2;
    }
    for(i=0;i<n;i++)
    {
        if(ha[i]||hb[i])
            a++;
        if(ha[i]||1-hb[i])
            b++;
        if(1-ha[i]||hb[i])
            c++;
        if(1-ha[i]||1-hb[i])
            d++;
    }
    //printf("%lld %lld %lld %lld\n",a,b,c,d);
    for(i=0;i<n;i++)
    {
        if(ha[i]&&hb[i])
            sum+=a;
        if(ha[i]&&1-hb[i])
            sum+=b;
        if(1-ha[i]&&hb[i])
            sum+=c;
        if(1-ha[i]&&1-hb[i])
            sum+=d;
    }
    printf("%lld",sum);
}
