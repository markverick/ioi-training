#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char v[]={'f','e','d','a','b','c'};
char s[100],ch;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k,n,len,row;
	scanf("%s",s);
	len=strlen(s);
	ch=s[len-1];
	s[len-1]=0;
	sscanf(s,"%I64d",&n);
	n--;
	k=(n/4)*2*6;
	if(n%2)k+=6;
	k+=n;
	if(n%4>1)
		k-=2;
	for(i=0;i<6;i++)
	{
		k++;
		if(v[i]==ch)
			break;
	}
	printf("%I64d",k);
}