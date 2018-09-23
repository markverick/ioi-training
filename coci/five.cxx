#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[7];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,mc=0;
	for(i=1;i<=5;i++)
    {
        for(j=1;j<=4;j++)
        {
            scanf("%d",&k);
            a[i]+=k;
        }
        mc=max(mc,a[i]);
    }
    for(i=1;i<=5;i++)
    {
        if(a[i]==mc)
            printf("%d %d",i,a[i]);
    }
}
