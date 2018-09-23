#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long a[200135],hsh[200135],isp[200135];
vector<long long> prm;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k,n;
	for(i=2;i<=200000;i++)
    {
        if(!hsh[i])
        {
            isp[i]=1;
            prm.emplace_back(i);
            for(j=i;j<=200000;j+=i)
                hsh[j]=1;
        }
    }
	scanf("%I64d",&n);
	long long sm=0,x,mc=0;
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
    }
    sort(&a[1],&a[n+1]);
	for(j=1;j<=sqrt(n);j++)
    {
        if(!isp[a[j]])continue;
        isp[a[j]]=0;
        x=a[j];
        sm=0;
        for(i=j+1;i<=n;i++)
        {
            sm+=(a[i]/x)*x;
        }
        mc=max(mc,sm+x);
    }
    printf("%I64d",mc);
}
