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
	int i,j,k,a,b,c;
	scanf("%d %d",&a,&b);
	c=a*b;
	for(i=1;i<=5;i++)
    {
        scanf("%d",&a);
        printf("%d ",a-c);
    }
}
