#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
pair<int,int> operator +(pair<int,int> a,pair<int,int> b)
{
	return MP(a.X+b.X,a.Y+b.Y);
}
// int operator *(tuple<int,int,int>a,tuple<int,int,int> b)
// {
// 	int x,y,z,X,Y,Z;
// 	tie(x,y,z)=a;
// 	tie(X,Y,Z)=b;
// 	return (x*X+y*X)*(z+Z);
// }
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	pair<int,int> a,b;
	tuple<int,int,int> x,y;
	a=MP(1,3);
	b=MP(30,10);
	x=MT(1,2,3);
	y=MT(4,5,6);
	printf("%d %d\n",(a+b).X,(a+b).Y);
	// printf("%d\n",x*y);
}