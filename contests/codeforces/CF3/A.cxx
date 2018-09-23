#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char a[200135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j=0,k;
	scanf("%d",&n);
	scanf("%s",a+1);
	for(i=1;i<=n;i++)
	{
		if(a[i]!='<')
			break;
		j++;
	}
	for(i=n;i>=1;i--)
	{
		if(a[i]!='>')
			break;
		j++;
	}
	printf("%d",j);
}