#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long hr[2000135],hl[2000135],odd[2000135],even[2000135],n;
void addO(long long idx,long long val)
{
    idx++;
    while(idx<=n*2+5)
    {
        odd[idx]+=val;
        idx+=idx&-idx;
    }
}
long long sumO(long long idx)
{
    idx++;
    long long sm=0;
    while(idx>0)
    {
        sm+=odd[idx];
        idx-=idx&-idx;
    }
    return sm;
}
void addE(long long idx,long long val)
{
    idx++;
    while(idx<=n*2+5)
    {
        even[idx]+=val;
        idx+=idx&-idx;
    }
}
long long sumE(long long idx)
{
    idx++;
    long long sm=0;
    while(idx>0)
    {
        sm+=even[idx];
        idx-=idx&-idx;
    }
    return sm;
}
int main()
{
	long long i,j,k,T,m,x,y,a,b,c,d,A,B,C,D,sum,cross=0;
	scanf("%lld",&T);
	while(T--)
    {
        a=0;b=0;c=0;d=0;sum=0;cross=0;
        memset(odd,0,sizeof odd);
        memset(even,0,sizeof even);
        memset(hl,0,sizeof hl);
        memset(hr,0,sizeof hr);
        scanf("%lld %lld",&n,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%lld %lld",&x,&y);
            hl[n+x-y]=1;
            hr[x+y-1]=1;
        }
        for(i=1;i<=n*2;i++)
        {
            if(hl[i])
            {
                sum+=i<=n?i:2*n-i;
                if(i%2)
                    addO(i,1);
                else
                    addE(i,1);
            }
            if(hr[i])
                sum+=i<=n?i:2*n-i;
        }
        for(i=1;i<=n*2;i++)
        {
            if(!hr[i])
                continue;
            if(i<=n)
                A=i;
            else
                A=2*n-i;
            if((i+n%2)%2==0)
            {
                cross+=sumO(n+A-1)-sumO(n-A);
//                printf("1) %lld %lld\n",n+A-1,n-A);
//                printf("2) %lld %lld\n",sumO(n+A-1),sumO(n-A));
            }
            else
            {
                cross+=sumE(n+A-1)-sumE(n-A);
//                printf("%lld %lld\n",sumO(n+A-1),sumO(n-A));

            }
//            printf("!%lld %lld\n",i,cross);
        }
//        printf("%lld %lld %lld\n",n*n,sum,cross);
        printf("%lld\n",n*n-sum+cross);
    }
}
