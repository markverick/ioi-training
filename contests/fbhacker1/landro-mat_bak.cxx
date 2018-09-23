#include<bitss/stdc++.h>
#define MI 1000000000000000000
using namespace std;
long long a[100135];
int main()
{
    long long T,t,i,j,k,n,m,L,d,fst,mid,lst,st,ed,md,sum,mc,sm,f,mn;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d %d %d",&L,&n,&m,&d);
        for(i=1;i<=n;i++)
        {
            scanf("%d",a[i]);
        }
        fst=0;lst=MI;
        while(fst<=lst)
        {
            mid=(fst+lst)/2;
            sum=0;
            for(i=1;i<=n;i++)
            {
                sum+=mid/a[i];
            }
            if(sum<L)
            {
                fst=mid+1;
            }
            else
            {
//                st=1;ed=lst;mn=MI;f=0;
//                while(st<=ed)
//                {
//                    md=(st+ed)/2;
//                    sm=0;
//                    for(j=1;j<=n;j++)
//                    {
//                        sm+=md/a[j];
//                    }
//                    if(sm<L)
//                    {
//                        st=md+1;
//                    }
//                    else
//                    {
//                        mn=md;
//                        ed=md-1;
//                    }
//                }
                for(j=1;j<=n;j++)
                {
                    if(1+d/a[j]<=m)
                    {
                        st=1;ed=mid/a[j];
                        while(st<=ed)
                        {
                            md=(st+ed)/2;
                            md*a[j]
                        }
                        if((md/a[j])*a[i]+d>mid)
                        {
                            f=1;
                        }
                    }
                    else
                    {
                        s
                    }
                }
            }
        }
    }
}
