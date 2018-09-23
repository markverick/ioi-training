#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j=0,k,a,b,c=1;
	scanf("%lld %lld",&a,&b);
	k=b;
	while(b--)
        c*=10;
    if(a%c>=c/2)
    {
        printf("%lld",a/c+1);
        if(a/c+1==0)
            j=1;
    }
    else
    {
        printf("%lld",a/c);
        if(a/c==0)
            j=1;
    }
    if(j==0) while(k>0)
    {
        k--;
        printf("0");
    }
}
