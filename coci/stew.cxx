#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[12],b[12],n;
int gen(int idx,int prod,int sum,int fk)
{
    if(idx==n+1)
    {
        if(fk)
            return abs(prod-sum);
        return 1000000000;
    }
    return min(gen(idx+1,prod,sum,fk),gen(idx+1,prod*a[idx],sum+b[idx],fk+1));
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
    }
    printf("%d",gen(1,1,0,0));
}
