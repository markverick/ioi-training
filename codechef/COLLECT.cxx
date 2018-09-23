#include<bits/stdc++.h>
#define M 3046201
using namespace std;
long long ft[100135],fac[3100135],n;
char ch[10];
long long Pow(long long b,long long p)
{
    if(p==0)
        return 1;
    long long tmp=Pow(b,p/2);
    tmp*=tmp;tmp%=M;
    if(p%2)
        tmp*=b;
    return tmp%M;
}
void add(long long x,long long val)
{
    while(x<=n)
    {
        ft[x]+=val;
        x+=x&-x;
    }
}
long long sum(long long x)
{
    long long sm=0;
    while(x>0)
    {
        sm+=ft[x];
        x-=x&-x;
    }
    return sm;
}
long long qs(long long x,long long y)
{
    return sum(y)-sum(x-1);
}
void st(long long x,long long val)
{
    add(x,val-sum(x)+sum(x-1));
}
int main()
{
    long long i,j,k,Q,a,b,p,q,com,div;
    fac[0]=1;fac[1]=1;
    for(i=2;i<=3100000;i++)
        fac[i]=fac[i-1]*i,fac[i]%=M;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a);
        add(i,a);
    }
    scanf("%lld",&Q);
    while(Q--)
    {
        scanf("%s %lld %lld",ch,&a,&b);
        if(ch[0]=='c')
        {
            st(a,b);
        }
        else
        {
            p=qs(a,b);
            q=b-a+1;
            com=fac[q]*Pow((fac[q-p%q]*fac[p%q])%M,M-2);com%=M;
            com*=fac[p];com%=M;
            a=Pow(fac[p/q+1],p%q);
            b=Pow(fac[p/q],(q-p%q));
            com*=Pow((a*b)%M,M-2);com%=M;
            printf("%lld\n",com);
        }
    }
}
