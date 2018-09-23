#include<bits/stdc++.h>
#define MI 1000000000
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
	long long n,i,j,k,T,t;
	pair<long long,long long> a,fs,ls,md;
	scanf("%lld",&T);
	while(T--)
    {
        scanf("%lld/%lld",&a.X,&a.Y);
        fs=MP(0,1);ls=MP(1,0);md=MP(1,1);
        t=0;
        while(a.X*md.Y!=md.X*a.Y)
        {
            k=a.X*md.Y>md.X*a.Y;
//            printf("%lld/%lld %lld/%lld %lld/%lld\n",fs.X,fs.Y,md.X,md.Y,ls.X,ls.Y);
            if(k)
                fs=md;
            else
                ls=md;
            if(k^(t%2))
                printf("R");
            else
                printf("L");
            md=MP(fs.X+ls.X,fs.Y+ls.Y);
            t++;
        }
        printf("\n");
    }
}
