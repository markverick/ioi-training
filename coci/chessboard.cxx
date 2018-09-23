#include<bits/stdc++.h>
using namespace std;
char s[3][135];
int main()
{
	int r,c,i,j,k,a,b;
	scanf("%d %d %d %d",&r,&c,&a,&b);
	for(i=0;i<c;i++)
    {
        for(j=0;j<b;j++)
            s[i%2][i*b+j]='X';
        for(j=0;j<b;j++)
            s[1-i%2][i*b+j]='.';
    }
    for(i=0;i<r;i++)
        for(j=0;j<a;j++)
            printf("%s\n",s[i%2]);
}
