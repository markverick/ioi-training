#include<bits/stdc++.h>
using namespace std;
long long n,addVal,a,b,c,d,i,summation,toAdd,mn,mc;
long long ft[1135][1135];
void add(long long x,long long y,long long add)
{
    long long y_bak=y;
    while(x<=n)
    {
        y=y_bak;
        while(y<=n)
        {
            ft[x][y]+=add;
            y+=y&(-y);
        }
        x+=x&(-x);
    }
}
long long sum(long long x,long long y)
{
    long long s=0;
    long long y_bak=y;
    while(x>=1)
    {
        y=y_bak;
        while(y>=1)
        {
            s+=ft[x][y];
            y-=y&(-y);
        }
        x-=x&(-x);
    }
    return s;
}
int main()
{
    int ch;
    while(scanf("%d",&ch)!=EOF)
    {
        switch (ch)
        {
        case 0:
            scanf("%lld",&n);
            break;
        case 1:
            scanf("%lld %lld %lld",&a,&b,&addVal);
            a++;b++;
            add(a,b,addVal);
            break;
        case 2:
            scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
            a++;b++;c++;d++;
            printf("%lld\n",sum(c,d)-sum(c,b-1)-sum(a-1,d)+sum(a-1,b-1));
            break;
        case 3:
            return 0;
            break;
        }
    }
}
