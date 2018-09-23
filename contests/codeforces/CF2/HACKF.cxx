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
	int n=200000,i,j;
	srand(135);
	printf("%d\n",n);
	for(i=1;i<=n;i++)
    {
        printf("%d\n",rand()%100000+100000);
    }
}
