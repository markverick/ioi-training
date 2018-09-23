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
	int i,j,k,x,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%x",&x);
        if(x<0x20)
            printf(".");
        else
            printf("-");
    }
}
