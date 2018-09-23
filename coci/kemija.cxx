#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long b[10135],a[10135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k,n,sum=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
        scanf("%lld",&b[i]),sum+=b[i];
    sum/=3;
    if(n%3)
    {
        a[0]=1;
        j=0;i=3%n;
        while(i!=0)
        {
            a[i]=a[j]+b[(j+2)%n]-b[(j+1)%n];
            j=i;i=(i+3)%n;
        }
        k=0;
        for(i=0;i<n;i++)
            k+=a[i];
//        printf("%lld %lld %lld\n",sum,k,sum-k);
        j=(sum-k)/n;
        for(i=0;i<n;i++)
        {
            a[i]+=j;
            printf("%lld\n",a[i]);
        }
    }
    else
    {
        a[0]=0;k=0;
        for(i=3;i<n;i+=3)
            a[i]=a[i-3]+b[i-1]-b[i-2],k=min(k,a[i]);
        for(i=0;i<n;i+=3)
            a[i]+=-k+1;
        a[2]=0;k=0;
        for(i=5;i<n;i+=3)
            a[i]=a[i-3]+b[i-1]-b[i-2],k=min(k,a[i]);
        for(i=2;i<n;i+=3)
            a[i]+=-k+1;
        for(i=1;i<n;i+=3)
            a[i]=b[i]-a[i-1]-a[i+1];
        k=0;
        for(i=0;i<n;i++)
            k+=a[i];
//        for(i=0;i<n;i++)
//            printf("%lld ",a[i]);
        j=(sum-k)/n;
        for(i=0;i<n;i++)
        {
            a[i]+=j;
            printf("%lld\n",a[i]);
        }
    }
}
