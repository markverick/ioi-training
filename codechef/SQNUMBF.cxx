#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long a[111],hsh[1000135];
vector<long long> p;
int main()
{
	//freopen("out.txt","w",stdout);

	//freopen("in.txt","r",stdin);
	long long i,j,k,T,g,f,n;
    for(i=2;i<=1000000;i++)
    {
        if(hsh[i]==0)
        {
            p.emplace_back(i);
            for(j=i;j<=1000000;j+=i)
                hsh[j]=1;
        }
    }
	scanf("%lld",&T);
	while(T--)
    {
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        f=0;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(__gcd(a[i],a[j])>1)
                {
                    printf("%lld\n",__gcd(a[i],a[j]));
                    f=1;
                    break;
                }
            }
            if(f==1)break;
        }
        if(f==0)
        {
            f=0;
            for(i=1;i<=n;i++)
            {
                for(j=0;j<p.size();j++)
                {
                    if(p[j]*p[j]>a[i])
                        break;
                    if(a[i]%(p[j]*p[j])==0)
                    {
                        f=1;
                        printf("%lld\n",p[j]);break;
                    }
                }
                if(f==0)for(j=1;j<=1000000;j++)
                {
                    if(j==a[i])break;
                    if(a[i]%j==0)
                    {
                        k=sqrt(a[i]/j)+0.00001;
                        if(k*k==a[i]/j)
                        {
                            printf("%lld\n",a[i]/j);
                            f=1;break;
                        }
                    }
                }
                if(f==1)break;
            }
        }
    }
}
