#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int d[6]={2,0,3,1};
double a[6],b[6];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,r=0;
	double mc=0,x;
	scanf("%lf %lf %lf %lf",&a[0],&a[1],&a[2],&a[3]);
	mc=a[0]/a[2]+a[1]/a[3];
//	printf("%f\n",mc);
	for(i=1;i<=3;i++)
    {
        for(j=0;j<4;j++)
            b[j]=a[d[j]];
        for(j=0;j<4;j++)
            a[j]=b[j];
        x=a[0]/a[2]+a[1]/a[3];
//        printf("%f %f\n%f %f\nmc = %f\n",a[0],a[1],a[2],a[3],mc);
        if(mc<x)
            mc=x,r=i;
    }
    printf("%d",r);
}
