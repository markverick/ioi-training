#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char s[10][15]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,d,m,sum=2;
	scanf("%d %d",&d,&m);
	for(i=1;i<m;i++)
    {
        sum+=a[i];
    }
    sum+=d;
    printf("%s",s[sum%7]);

}
