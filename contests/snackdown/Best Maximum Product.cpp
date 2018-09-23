#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
vector<pair<long long,long long > > v;
long long Pow(long long b,long long p)
{
    if(p==0)
        return 1;
    long long temp=Pow(b,p/2);
    temp*=temp;
    temp%=1000000007;
    if(p%2)temp*=b;
    temp%=1000000007;
    return temp;
}
int main()
{
    long long n,m,i,j,k,T,a,zero=0,prod=1,P,N,fu,tmp,x,y;
    double lgx,lgy,lg;
    scanf("%lld",&T);
    while(T--)
    {
        v.clear();fu=0;x=0;y=0;
        zero=0;
        scanf("%lld %lld",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a);
            if(a==0)
                zero=1;
            if(a>=0)
                v.emplace_back(a,1);
            else
                v.emplace_back(-a,0);
        }
        sort(v.begin(),v.end());
        long long sg=1;
        prod=1;fu=0;lg=0.0;
        for(i=v.size()-1;i>=v.size()-m;i--)
        {
            if(v[i].Y==0)
            {
                sg=1-sg;
            }
            prod*=v[i].X;
            prod%=1000000007;
            lg+=log(v[i].X);
        }
        if(sg==1)
        {
            printf("%lld\n",prod);
        }
        else
        {
            lgx=-1;lgy=-1;
            P=-1;N=-1;
            for(i=v.size()-1;i>=v.size()-m;i--)
            {
                if(v[i].Y==1)
                    P=i;
                else
                    N=i;
            }
            if(P>=0) for(i=v.size()-m-1;i>=0;i--)
            {
                if(v[i].Y==0)
                {
                    x=prod*Pow(v[P].X,1000000005);
                    x%=1000000007;
                    x*=v[i].X;
                    x%=1000000007;
                    lgx=lg-log(v[P].X)+log(v[i].X);
                    fu=1;
                    break;
                }
            }
            if(N>=0) for(i=v.size()-m-1;i>=0;i--)
            {
                if(v[i].Y==1)
                {
                    y=prod*Pow(v[N].X,1000000005);
                    y%=1000000007;
                    y*=v[i].X;
                    y%=1000000007;
                    lgy=lg-log(v[N].X)+log(v[i].X);
                    fu=1;
                    break;
                }
            }
            if(fu==1)
            {
                if(lgx>=lgy)
                    printf("%lld\n",x);
                else
                    printf("%lld\n",y);
            }
            else
            {
                if(zero==1)
                {
                    printf("0\n");
                }
                prod=1;
                for(i=0;i<m;i++)
                {
                    prod*=v[i].X;
                    prod%=1000000007;
                }
                prod=1000000007-prod;
                prod%=1000000007;
                printf("%lld\n",prod);
            }
        }
    }
}
