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
	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	srand(135);
	int i;
	printf("Yes\nBecause ");
	for(i=1;i<=30000;i++)
	{
		printf("%c",'a'+rand()%4);
		if(i%(rand()%10+5)==0)printf(". %c",'A'+rand()%4);
		else if(i%(rand()%3+4)==0)printf(" ");
	}
	printf(".");
}