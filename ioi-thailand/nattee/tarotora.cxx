#include<bits/stdc++.h>
#define MI 1000000005
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long a[100135],b[100135],A,B;
vector<long long> va,vb;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,i,j,k,T,m,sum=0;
    scanf("%lld",&T);
    while(T--)
    {
        va.clear();vb.clear();
        scanf("%lld %lld",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%lld %lld",&a[i],&b[i]);
        sum=0;
        A=0;B=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]<=b[i])
                sum+=a[i],va.emplace_back(b[i]-a[i]),A++;
            else
                sum+=b[i],vb.emplace_back(a[i]-b[i]),B++;
        }
        sort(va.begin(),va.end());
        sort(vb.begin(),vb.end());
        i=0;
        while(B-A>m)
        {
            sum+=vb[i];A++;B--;
        }
        while(A-B>m)
        {
            sum+=va[i];A--;B++;
        }
        printf("%lld\n",sum);
    }
}
