#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,x[100135],y[100135];
vector<int> row[100135];
vector<int> col[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,xx,yy;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
        row[x[i]].emplace_back(y[i]);
        col[y[i]].emplace_back(x[i]);
    }
    for(i=1;i<=100000;i++)
    {
        sort(row[i].begin(),row[i].end());
        sort(col[i].begin(),col[i].end());
    }
    long long sum=0,a,b,c,d;
    for(i=1;i<=n;i++)
    {
        xx=lower_bound(row[x[i]].begin(),row[x[i]].end(),y[i])-row[x[i]].begin();
        yy=lower_bound(col[y[i]].begin(),col[y[i]].end(),x[i])-col[y[i]].begin();
        a=xx-0;b=row[x[i]].size()-xx-1;
        c=yy-0;d=col[y[i]].size()-yy-1;
        sum+=a*c+c*b+b*d+d*a;
    }
    printf("%lld",sum);
}
