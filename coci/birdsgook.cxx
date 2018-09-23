#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[135];
char a[]={"ABC"},b[]="BABC",g[]="CCAABB";
int main()
{
	int i,j,k,n,A=0,B=0,G=0,mc=0;
	scanf("%d %s",&n,s);
	for(i=0;i<n;i++)
    {
        if(s[i]==a[i%3])
            A++;
        if(s[i]==b[i%4])
            B++;
        if(s[i]==g[i%6])
            G++;
    }
    mc=max(A,B);
    mc=max(mc,G);
    printf("%d\n",mc);
    if(A==mc)
        printf("Adrian\n");
    if(B==mc)
        printf("Bruno\n");
    if(G==mc)
        printf("Goran\n");
}
