#include<bits/stdc++.h>
using namespace std;
long long a[111],b[111],c[111],d[111];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k,n,m,T,fst,mid,lst,sum,mn=1000000000000000000,x,y,X,Y;
	scanf("%lld",&T);
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
        scanf("%lld %lld",&a[i],&b[i]);
    scanf("%lld",&m);
    for(i=1;i<=m;i++)
        scanf("%lld %lld",&c[i],&d[i]);
    fst=0;lst=T;
    while(fst<=lst)
    {
        mid=(fst+lst)/2;
//        printf("%lld <- %lld -> %lld\n",fst,mid,lst);
        X=0;
        for(i=1;i<=n;i++)
        {
            if(mid>=a[i])
            {
                X++;
                X+=(mid-a[i])/b[i];
            }
        }
        x=1;
        for(i=1;i<=n;i++)
        {
            if(mid-1>=a[i])
            {
                x++;
                x+=(mid-a[i]-1)/b[i];
            }
        }
        Y=0;
        for(i=1;i<=m;i++)
        {
            if(T-mid>=c[i])
            {
                Y++;
                Y+=(T-mid-c[i])/d[i];
            }
        }
        y=1;
        for(i=1;i<=m;i++)
        {
            if(T-mid-1>=c[i])
            {
                y++;
                y+=(T-mid-c[i]-1)/d[i];
            }
        }
//        printf("%lld <-> %lld, %lld <-> %lld\n",x,X,y,Y);
        if(X>=y&&Y>=x)
        {
            mn=min(mn,mid);
            lst=mid-1;
        }
        else if(Y<x)
        {
            lst=mid-1;
        }
        else
        {
            fst=mid+1;
        }

    }
    printf("%lld",mn);

}
