#include<bits/stdc++.h>
using namespace std;
char str[15];
int out[7];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,in,len,dec,a,b=1,c;
	scanf("%d.%s",&in,str);
	len=strlen(str);
	sscanf(str,"%d",&a);
	while(len--)
        b*=10;
    c=__gcd(a,b);
    while(c>1)
    {
        a/=c;b/=c;
        c=__gcd(a,b);
    }
    a+=in*b;
    int n=b,sum=a;
    for(i=5;i>1;i--)
    {
        out[i]=(sum-n)/(i-1);
        n-=out[i];
        sum-=out[i]*i;
        if(n<=0||sum<=0)break;
    }
    out[1]=n;
    for(i=1;i<=5;i++)
        printf("%d ",out[i]);
}
