#include<bits/stdc++.h>


int main()
{
    int T,t,i,j,k;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        int l,d,h,v;
        scanf("%d %d %d %d",&l,&d,&h,&v);
        h=double(h);
        double ans=v*sqrt(2.0*h/9810.0);
        //printf("%lf",ans);
        if(ans<d-500)
            printf("FLOOR\n");
        else if(ans<=d+500)
            printf("EDGE\n");
        else if(ans<d+l-500)
            printf("POOL\n");
        else if(ans<=d+l+500)
            printf("EDGE\n");
        else
            printf("FLOOR\n");

    }
}
