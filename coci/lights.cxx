#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int d[111],r[111],g[111];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,l,t=0,s=0,id;
    scanf("%d %d",&n,&l);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&d[i],&r[i],&g[i]);
    }
    for(i=1;i<=n;i++)
    {
        if((t+d[i])%(r[i]+g[i])<r[i])
            t+=r[i]-(t+d[i])%(r[i]+g[i]);
    }
    printf("%d",t+l);
}
