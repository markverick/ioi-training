#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
double adj[135][135];
double Max[135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,n,m,k,a;
	double b;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d %lf",&a,&b);
            adj[a][i]=b;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            Max[i]=max(Max[i],adj[i][j]);
    }
    sort(&Max[1],&Max[n+1]);
    double sum=0;
    for(i=n;i>n-k;i--)
    {
        sum+=Max[i];
    }
    printf("%.1f",sum);
}
