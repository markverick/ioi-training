#include<bits/stdc++.h>
#define EPS 0.0000000001
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k,l,x,y,B;
	double a,b,X,Y,bd;
    for(i=1;i<1000;i++)
    {
        for(j=i;i+j<=1000-i;j++)
        {
            B=max(i+j,i*j/100);
            for(k=2000;k>=B;k--)
            {
//                i=50;j=100;k=2000;
                if((k*1000000)%(i*j))
                    continue;
                X=(double)(k-i-j)/100;Y=(double)k*100/(i*j);
//                if(X<0)
//                {
//                    printf("%lld %lld = %lld\n",i,j,k);
//                    system("pause");
//                }
//                printf("!%f %f\n",X,Y);
                if(X*X-4*Y<0)
                    continue;
//                printf("!\t%f %f\n",X,Y);
                a=(X-sqrt(X*X-Y*4))/2;
                b=(X+sqrt(X*X-Y*4))/2;
//                printf("!%f %f [%f] <> %f\n",a,b,X/2,sqrt(X*X-Y*4)/2);                x=nearbyint(a*100);
                y=nearbyint(b*100);
//                printf("%lld %lld\n",x,y);
                if(x>=1&&x<=2000&&y>=1&&y<=2000&&x>=j&&y>=x)
                {
//                    printf("%lld %lld %lld %lld\n",i,j,x,y);
                    if(i*j*x*y==(i+j+x+y)*1000000)
                        printf("%lld.%02lld %lld.%02lld %lld.%02lld %lld.%02lld\n",i/100,i%100,j/100,j%100,x/100,x%100,y/100,y%100);
                }
            }
        }
    }
}
