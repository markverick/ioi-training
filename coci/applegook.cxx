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
	int i,j,k,a,b,c,sq,cot=0;
	double sd;
	scanf("%d %d",&a,&b);
    c=__gcd(a,b);
    sd=sqrt(c);
    sq=nearbyint(sd);
    for(i=1;i<sd;i++)
    {
        if(c%i==0)
        {
            printf("%d %d %d\n",i,a/i,b/i);
            printf("%d %d %d\n",c/i,a/(c/i),b/(c/i));
        }
    }
    if(sq*sq==c)
        printf("%d %d %d\n",sq,a/sq,b/sq);
}
