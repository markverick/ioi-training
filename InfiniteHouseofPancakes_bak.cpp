#include<bits/stdc++.h>
using namespace std;
int a[120000];
int main()
{
    //freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,t,i,j,k;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        int d,sum=0;
        scanf("%d",&d);
        int mc=0;
        for(i=0;i<d;i++)
        {
            scanf("%d",&a[i]);
            mc=max(mc,a[i]);
        }

        while(true)
        {
            a[d++]=0;
            sort(&a[0],&a[d]);
            int x=(a[d-1]+a[0]+1) /2;
            int y=(a[d-1]+a[0]) /2;
            if(mc- max(a[d-2],x)>=2)
            {
                a[0]=y ;
                a[d-1]=x ;
                mc=max(a[d-1],a[d-2]);
                //printf("%d %d %d\n",x,y,mc);
                sum++;
            }
            else
                break;

        }
        printf("Case #%d: %d\n",t+1,mc+sum);
    }
}
