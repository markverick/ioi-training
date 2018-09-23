#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,m,mc=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
            for(k=j+1;k<=n;k++)
                if(a[i]+a[j]+a[k]<=m)
                    mc=max(mc,a[i]+a[j]+a[k]);
    printf("%d",mc);

}
