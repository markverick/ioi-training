#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[12],hsh[1135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n=10,sum=0,mn=1000000000,x=-1;
	hsh[0]=1;
	for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        hsh[sum]=1;
    }
    for(i=1000;i>=0;i--)
    {
        if(hsh[i]==0)continue;
        if(mn>abs(100-i))
            mn=abs(100-i),x=i;
        else if(mn==abs(100-i))
            x=max(x,i);
    }
    printf("%d",x);
}
