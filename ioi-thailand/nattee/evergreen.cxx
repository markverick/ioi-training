#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long a[1135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,m,i,j,k,fs=1,md,ls=MI,sum,w,mn=MI,x,y;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(&a[1],&a[n+1]);
    while(fs<=ls)
    {
        md=(fs+ls)/2;
        sum=0;
//        printf("%lld <- %lld -> %lld\n",fs,md,ls);
        for(i=1;i<n;i++)
        {
            w=a[i+1]-a[i];
            if(w%2)
            {
                x=md;
                y=max(0ll,(md-w/2));
                sum+=(x+y)*(x-y+1)-md;
            }
            else
            {
                x=md;
                y=max(0ll,(md-w/2+1));
                sum+=(x+y)*(x-y+1)-md;
                sum+=max(0ll,md-w/2);
            }
        }
        sum+=md*(md+1)-md;
        if(sum>=m)
        {
            mn=min(mn,md);
            ls=md-1;
        }
        else
            fs=md+1;
//        system("pause");
    }
    printf("%lld",mn-1);


}
