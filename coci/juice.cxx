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
	int i,j,k,A,B,C,a,b,c;
	double x,y,z,mn;
	scanf("%d %d %d %d %d %d",&A,&B,&C,&a,&b,&c);
	x=(double)A/a;
	y=(double)B/b;
	z=(double)C/c;
	mn=min(x,y);
	mn=min(mn,z);
	printf("%f %f %f",A-mn*a,B-mn*b,C-mn*c);
}
