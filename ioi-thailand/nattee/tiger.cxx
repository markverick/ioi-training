#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
pair<int,int> f[1135],t[1135];
int d[1135],hsh[2000135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,mc=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
        scanf("%d %d",&f[i].X,&f[i].Y);
	for(i=1;i<=m;i++)
        scanf("%d %d",&t[i].X,&t[i].Y),d[i]=MI;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            d[i]=min(d[i],abs(t[i].X-f[j].X)+abs(t[i].Y-f[j].Y));
        }
        hsh[d[i]]++;
        mc=max(mc,hsh[d[i]]);
    }
    printf("%d",mc);


}
