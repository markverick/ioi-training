#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,t,i,j,k,p,x,y;
	double d;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d %d %d",&p,&x,&y);
		if(hypot(x-50,y-50)>50.0)
		{
			printf("Case #%d: white\n",t);
			continue;
		}
		d=atan2(x-50,y-50);
		if(d<0)d=acos(-1.0)*2.0+d;
		if(d<(double)p/100.0*acos(-1.0)*2.0)
			printf("Case #%d: black\n",t);
		else
			printf("Case #%d: white\n",t);
	}
}