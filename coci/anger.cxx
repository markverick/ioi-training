#include<bits/stdc++.h>
#define MI 20000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long a[100135],b[100135];
int main()
{
	//freopen("out.txt","w",stdout);
//	freopen("in.txt","r",stdin);
    long long i,j,k,n;
    long long m,fst=0,lst=0,mid,mn=MI;
    scanf("%lld %lld",&m,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&b[i]);
        lst=max(lst,b[i]);
    }
    long long sum=0;
    fst++;lst++;
    while(fst<=lst)
    {
        mid=(fst+lst)/2;
        mid--;
//        printf("%lld <- %lld -> %lld\n",fst,mid,lst);
        sum=0;
        for(i=1;i<=n;i++)
        {
            if(b[i]>=mid)
                sum+=b[i]-mid;
        }
//        printf("%lld / %lld\n",m,sum);
        mid++;
        if(m<sum)
        {
            fst=mid+1;
        }
        else
        {
            mn=min(mn,mid-1);
            lst=mid-1;
        }
    }
//    printf("!%lld\n",mn);
    sum=0;
    for(i=1;i<=n;i++)
    {
        if(b[i]>=mn)
            a[i]=b[i]-mn;
        else
        {
            a[i]=0ll;
        }
        sum+=a[i];
//        printf("%lld ",a[i]);
    }
//    printf("\n%lld %lld / %lld\n",mn,sum,m);
    for(i=1;i<=n;i++)
    {
        if(sum<m&&b[i]>=mn&&a[i]<=b[i]-mn)
        {
            sum++;
            a[i]++;
        }
    }
    long long cot=0,COT=0,x;
    for(i=1;i<=n;i++)
    {
//        printf("%lld - %lld = %lld\n",b[i],a[i],b[i]-a[i]);
        x=b[i]-a[i];
        cot+=x*x;
    }
    printf("%lld",cot);
}
