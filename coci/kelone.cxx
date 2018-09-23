#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char a[100135],b[100135],c[200135],offa[200135],offb[200135];
int main()
{
	int i,j,k,l,n,m,T;
	scanf("%d %d",&n,&m);
	scanf("%s %s",a,b);
    scanf("%d",&T);
    for(i=0;i<n;i++)
    {
        offa[100000+i]=a[n-i-1];
    }
    for(i=0;i<m;i++)
    {
        offb[100000+i-T+n-1]=b[i];
    }
    for(i=0;i<=200000;i++)
    {
        if(offa[i])
            printf("%c",offa[i]);
        if(offb[i])
            printf("%c",offb[i]);
    }
}
