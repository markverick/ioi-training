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
	int i,j,k,n,sum=0;
	scanf("%d",&n);
	for(i=0;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            sum+=i+j;
        }
    }
    printf("%d",sum);
}
