#include<stdio.h>
#include<map>
using namespace std;
map<long long,long long> jum;
long long n,p,q;

long long fx(long long idx)
{
    if(jum[idx]>0)
    {
        return jum[idx];
    }
    if(idx<=0)
    {
        return 1;
    }
    return jum[idx]=fx(idx/p)+fx(idx/q);

}
int main()
{

    int i,j,k;
    while(scanf("%lld %lld %lld",&n,&p,&q)!=EOF)
    {
        jum.clear();
        printf("%lld\n",fx(n));

    }


}
