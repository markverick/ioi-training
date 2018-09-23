#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[10135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,m,bd=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
        scanf("%d",&a[i]),bd=max(bd,a[i]);
    long long fs=bd,md,ls=2000000,mc=-1,sum;
    while(fs<=ls)
    {
        md=(fs+ls)/2;
        sum=0;j=1;
//        printf("%lld <- %lld -> %lld\n",fs,md,ls);
        for(i=1;i<=n;i++)
        {
            if(sum+a[i]>md)
            {
                sum=a[i];
                j++;
            }
            else
                sum+=a[i];
        }
        if(j==m)
        {
            mc=max(mc,md);
            fs=md+1;
        }
        else if(j<m)
            ls=md-1;
        else
            fs=md+1;
    }
    if(mc>=0)
        printf("%lld",mc);
    else
        printf("IMPOSSIBLE");
}
