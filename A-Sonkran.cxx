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
	int a,b,i,j,k,ca,cb;
	scanf("%d %d",&ca,&a);
	scanf("%d %d",&cb,&b);
	if(a+b<=cb)
		printf("%d %d\n",0,a+b);
	else
		printf("%d %d\n",a+b-cb,cb);
}	