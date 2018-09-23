#include<bits/stdc++.h>
using namespace std;
int extgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int tmpx,tmpy,d;
	d=extgcd(b,a%b,x,y);
	tmpx=y;
	tmpy=x-a/b*y;
	x=tmpx;
	y=tmpy;
	return d;
}
int main()
{
	int x,y,a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",extgcd(a,b,x,y));
	printf("%d %d\n",x,y);
}