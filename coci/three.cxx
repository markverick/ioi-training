#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
	int i,j,k,a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a+b==c)
        printf("%d+%d=%d",a,b,c);
    else if(a==b+c)
        printf("%d=%d+%d",a,b,c);
    else if(a-b==c)
        printf("%d-%d=%d",a,b,c);
    else if(a==b-c)
        printf("%d=%d-%d",a,b,c);
    else if(a*b==c)
        printf("%d*%d=%d",a,b,c);
    else if(a==b*c)
        printf("%d=%d*%d",a,b,c);
    else if(b>0&&a%b==0&&a/b==c)
        printf("%d/%d=%d",a,b,c);
    else if(c>0&&b%c==0&&a==b/c)
        printf("%d=%d/%d",a,b,c);

}
