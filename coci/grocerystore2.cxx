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
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,x,y;
	double a,b;
    for(i=1;i<=2000-3;i++)
    {
        for(j=i;i+j<=2000-2;j++)
        {
            for(k=1;k<=2000;k++)
            {
                i=50;j=100;k=2000;
                if(i+j>k||i*j>k*100)continue;
                if((k*1000000)%(i*j))
                    continue;
                x=k-i-j;y=k*1000000/(i*j);
                if(x<0)
                {
                    printf("%d %d = %d\n",i,j,k);
                    system("pause");
                }
                if(x*x-4.0*y/100<0)
                    continue;
                printf("!%d %d\n",x,y);
                a=((double)x-sqrt(x*x-4.0*y/100))/2;
                b=((double)x+sqrt(x*x-4.0*y/100))/2;
                printf("!%f %f\n",a,b);                x=nearbyint(a);
                y=nearbyint(b);
                if(x>=1&&x<=2000&&y>=1&&y<=2000)
                {
                    printf("%d %d %d %d\n",i,j,x,y);
                    if(i*j*x*y==i+j+x+y)
                        printf("%d.%02d %d.%02d %d.%02d %d.%02d\n",i/100,i%100,j/100,j%100,x/100,x%100,y/100,y%100);
                }
                return 0;
            }
            return 0;
        }
    }
}
