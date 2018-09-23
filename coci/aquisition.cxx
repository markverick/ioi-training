#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[111];
int main()
{
	int i,j,k,n,L,R,mc=-1,id=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(&a[1],&a[n+1]);
    scanf("%d %d",&L,&R);
    if(L%2==0)
        L++;
    if(R%2==0)
        R--;
    if(L==R)
    {
        printf("%d",R);
        return 0;
    }
    if(R<a[1])
    {
        printf("%d",L);
        return 0;
    }
    if(L>a[n])
    {
        printf("%d",R);
        return 0;
    }
    for(i=2;i<=n;i++)
    {
        k=(a[i]+a[i-1])/2;j=(a[i]-a[i-1])/2;
        if(j%2==0)
        {
            j--;
            k--;
            if(k>=L&&k<=R)
            {
                if(mc<j)
                    mc=j,id=k;
            }
            k+=2;
            if(k>=L&&k<=R)
            {
                if(mc<j)
                    mc=j,id=k;
            }
        }
        else
        {
            if(k>=L&&k<=R)
            {
                if(mc<j)
                    mc=j,id=k;
            }
        }
    }
    k=lower_bound(&a[1],&a[n+1],L)-&a[0];
    if(k==1&&a[k]<=R)
    {
        if(mc<a[k]-L)
            mc=a[k]-L,id=L;
    }
    else if(k>1&&k<=n&&a[k]<=R)
    {
        j=min(L-a[k-1],a[k]-L);
        if(mc<j)
            mc=j,id=L;
    }
    k=upper_bound(&a[1],&a[n+1],R)-&a[1];
    if(k==n&&a[k]>=L)
    {
        if(mc<R-a[k])
            mc=R-a[k],id=R;
    }
    else if(k<n&&k>=1&&a[k]>=L)
    {
        j=min(R-a[k],a[k+1]-R);
        if(mc<j)
            mc=j,id=R;
    }
    printf("%d",id);
}
