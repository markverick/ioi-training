0#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
long long n;
long long prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
vector<pair<pair<long long,long long>,long long> > v,vec;
long long mi[52],M,Mi[52],a[52],b[52];
int main()
{
    long long i,j,k,T,N,m,tmp,c;
    scanf("%lld",&N);
    for(k=1;k<=N;k++)
    {
        scanf("%lld %lld",&m,&c);
        c%=m;
        for(i=0;i<15;i++)
        {

            if(m<=1)
                break;
            j=0;
            if(m%prime[i]==0)
            {
                tmp=1;
                while(m%prime[i]==0)
                {
                    tmp*=prime[i];
                    j++;
                    m/=prime[i];
                }
                v.emplace_back(make_pair(prime[i],j),c%tmp);
            }
        }
    }
    sort(v.begin(),v.end());
    for(i=1;i<v.size();i++)
    {
        if(v[i].X.X!=v[i-1].X.X)
        {
            vec.emplace_back(v[i-1]);
        }
    }
    vec.emplace_back(v.back());
//    for(i=0;i<vec.size();i++)
//        printf("%lld %lld %lld\n",vec[i].X.X,vec[i].X.Y,vec[i].Y);
    M=1;
    for(i=0;i<vec.size();i++)
    {
        a[i]=vec[i].Y;
        mi[i]=1;
        for(j=0;j<vec[i].X.Y;j++)
            mi[i]*=vec[i].X.X;
        M*=mi[i];
//        printf("ai = %lld, mi = %lld\n",a[i],mi[i]);
    }
    for(i=0;i<vec.size();i++)
        Mi[i]=M/mi[i];//,printf("Mi = %lld\n",Mi[i]);
//    printf("M = %lld",M);
    for(i=0;i<vec.size();i++)
    {
        for(j=1;j<mi[i];j++)
        {
            if((j*Mi[i])%mi[i]==1)
            {
                break;
            }
        }
        b[i]=j;
//        printf("Inverse of %lld = %lld mod %lld\n",a[i],b[i],mi[i]);
    }
    long long sum=0;
    for(i=0;i<vec.size();i++)
    {
//        printf("%lld %lld %lld\n",a[i],b[i],Mi[i]);
        sum+=(a[i]*b[i]*Mi[i]);
        sum%=M;
    }
    printf("%lld",sum);
}
