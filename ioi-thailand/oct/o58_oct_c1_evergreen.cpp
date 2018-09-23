#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
long long a[1135],mc=0,lo=0;
int main()
{
    long long n,i,j,t,x,y,fst=0,lst=400000000,mid;
    long long cot=0,m;
    scanf("%lld %lld",&n,&m);
    cot+=n;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        a[i]+=10000000000000000;
    }
    sort(&a[1],&a[n+1]);
    long long sum=0;
    long long mn=10000000000000000;
    while(fst<=lst)
    {
        mid=(fst+lst)/2;sum=0;
        //printf("%lld <- %lld -> %lld\n",fst,mid,lst);
           // printf("%lld\n",a[1]-mid+i);
//            h[a[1]-mid+i]=i+1;
            lo=(a[i]+a[i-1])/2;
            sum+=mid*mid/2;
            if(a[i]+a[i-1]%2==0)
            {
                sum+=(lo-a[i-1])*(lo-a[i-1]);
                sum+=(mid-(lo-a[i-1])+1)*(a[i]-a[i-1]+1)-mid-1;
            }
            else
            {
                sum+=(lo-a[i-1]+1)*(lo-a[i-1]+1);
                sum+=(a[i]-a[i-1]+1)*(mid-(lo-a[i-1]+1))-mid-1;
            }
            sum+=(mid+1)*(mid+1)/2;
//        for(i=0;i<=mid;i++)
//        {
//            h[a[n]+mid-i]=max(h[a[n]+mid-i],i+1);
//        }
//        for(i=a[1]-mid-1;i<=a[n]+mid+1;i++)
//        {
//            sum+=h[i];
//        }
       // printf("%lld\n",sum);
        if(sum>=m)
        {
            mn=min(mn,mid);
            lst=mid-1;
        }
        else
        {
            fst=mid+1;
        }
    }
    printf("%lld",mn);
}
