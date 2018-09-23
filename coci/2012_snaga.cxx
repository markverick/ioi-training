#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long str[50],hsh[50];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j=1,k,a,b,lcm=1,BD=41;
	scanf("%lld %lld",&a,&b);
	a--;
	for(i=2;135;i++)
    {
        lcm=i*lcm/__gcd(i,lcm);
        if(j>=100000000000000000)
            break;
        hsh[i]+=b/j-b/lcm;
        hsh[i]-=a/j-a/lcm;
        if(i==3)
        {
            if(a>=2)
                hsh[i]++;
            if(b>=2)
                hsh[i]--;
        }
        str[i]++;
        for(k=i+1;k<=BD;k++)
        {
            if(k%j==0&&k%i)
            str[k]+=str[i];
        }
        j=lcm;
    }
    long long sum=0;
    for(i=2;i<=BD;i++)
    {
//        printf("[%lld] %lld %lld\n",i,hsh[i],str[i]);
        sum+=(hsh[i])*(str[i]+1);
    }
    printf("%lld",sum);
}
