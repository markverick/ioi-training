#include<bits/stdc++.h>
#define MI 1000000000
#define EPS 0.000000001
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char ch[12][3];
double a[12],b[12],c[12],d[12],e[12],f[12];
double dx[6]={EPS,-EPS,0,0};
double dy[6]={0,0,EPS,-EPS};
double ang(double a,double b,double c,double d)
{
	return acos((a*c+b*d)/(hypot(a,b)*hypot(c,d)));
}
int main()
{
	// freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i=1,j,k,n,fk=0,l;
	double x,y;
	while(scanf("%s",ch[i]))
	{
		if(ch[i][0]=='*')break;
		n=i;
		if(ch[i][0]=='r')
		{
			scanf("%lf %lf %lf %lf",&a[i],&b[i],&c[i],&d[i]);
			swap(b[i],d[i]);
		}
		else if(ch[i][0]=='c')
			scanf("%lf %lf %lf",&a[i],&b[i],&c[i]);
		else
			scanf("%lf %lf %lf %lf %lf %lf",&a[i],&b[i],&c[i],&d[i],&e[i],&f[i]);
		i++;
	}
	i=1;
	while(scanf("%lf %lf",&x,&y))
	{
		k=0;
		if(abs(x-9999.9)<=EPS&&abs(y-9999.9)<=EPS)break;
		for(j=1;j<=n;j++)
		{
			// printf("%f %f %f %f %f %f\n",x,y,a[j],b[j],c[j],d[j]);
			if(ch[j][0]=='r')
			{
				if(x>a[j]&&x<c[j]&&y>b[j]&&y<d[j])
					printf("Point %d is contained in figure %d\n",i,j),k=1;
			}
			else if(ch[j][0]=='c')
			{
				if(hypot(a[j]-x,b[j]-y)<c[j])
					printf("Point %d is contained in figure %d\n",i,j),k=1;
			}
			else
			{
				if(abs(a[j]-x)<=EPS&&abs(b[j]-y)<=EPS||abs(c[j]-x)<=EPS&&abs(d[j]-y)<=EPS||abs(e[j]-x)<=EPS&&abs(f[j]-y)<=EPS)
					continue;
				fk=0;
				for(l=0;l<4;l++)
				{
					x+=dx[l];y+=dy[l];
					if(abs(ang(a[j]-x,b[j]-y,c[j]-x,d[j]-y)+ang(c[j]-x,d[j]-y,e[j]-x,f[j]-y)+ang(e[j]-x,f[j]-y,a[j]-x,b[j]-y)-acos(-1.0)*2) <=EPS)
						fk++;
					x-=dx[l];y-=dy[l];
				}
				if(fk==4)
					printf("Point %d is contained in figure %d\n",i,j),k=1;


			}

		}
		if(k==0)
				printf("Point %d is not contained in any figure\n",i);
		i++;
	}	
}