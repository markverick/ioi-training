#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char a[1135],b[1135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,x,y;
	scanf("%s %s",a,b);
	for(i=0;a[i];i++)
    {
        if(a[i]=='6')
            a[i]='5';
    }
    for(i=0;b[i];i++)
    {
        if(b[i]=='6')
            b[i]='5';
    }
    sscanf(a,"%d",&x);
    sscanf(b,"%d",&y);
    printf("%d ",x+y);
	for(i=0;a[i];i++)
    {
        if(a[i]=='5')
            a[i]='6';
    }
    for(i=0;b[i];i++)
    {
        if(b[i]=='5')
            b[i]='6';
    }
    sscanf(a,"%d",&x);
    sscanf(b,"%d",&y);
    printf("%d",x+y);
}
