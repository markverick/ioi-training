#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int c[135],mc;
pair<int,int> a[135],x[135];
vector<pair<int,int> > y;
int interval;
int main()
{
    int n,m,i,j,k,fu=0,T=0;
    //freopen("out.txt","w",stdout);
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        T++;
        //printf("\nCASE #%d: \n",T);
        if(n==0&&m==0)
            return 0;
        mc=0;fu=0;
        y.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&x[i].X,&x[i].Y);
            y.emplace_back(x[i].X,x[i].Y);
            mc=max(mc,x[i].Y);
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a[i].X,&a[i].Y,&c[i]);
            mc=max(mc,a[i].Y);
            y.emplace_back(a[i].X,a[i].Y);
        }
        for(i=1;i<=m;i++)
        {
            for(j=c[i];j<=1000000;j+=c[i])
            {
                y.emplace_back(j+a[i].X,j+a[i].Y);
            }
        }
        sort(y.begin(),y.end());
        for(i=1;i<y.size();i++)
        {
            //printf("%d %d\n",y[i].X,y[i].Y);
            if(y[i].X>1000000)
                continue;
            if(y[i].X<y[i-1].Y)
            {
                fu=1;break;
            }
        }
        if(fu==1)
            printf("CONFLICT\n");
        else
            printf("NO CONFLICT\n");
//        if(m>0&&fu==1)
//        {
//            printf("CONFLICT\n");
//            continue;
//        }
//        if(n>0)
//            sort(&x[1],&x[n+1]);
//        if(m>0)
//        {
//            sort(&a[1],&a[m+1]);
//            for(i=2;i<=m;i++)
//            {
//                if(a[i].X<a[i-1].Y)
//                {
//                    fu=1;break;
//                }
//            }
//            if(fu==1)
//            {
//                printf("CONFLICT\n");
//                continue;
//            }
//
//            for(j=interval;j<=mc;j+=interval)
//            {
//                for(i=1;i<=m;i++)
//                {
//                    //printf("J %d %d %d\n",j,j+a[i].X,j+a[i].Y);
//                    y.emplace_back(j+a[i].X,j+a[i].Y);
//                }
//            }
//            sort(y.begin(),y.end());
//            //printf("%d %d\n",y[0].X,y[0].Y);
//            for(i=1;i<y.size();i++)
//            {
//                //printf("%d %d\n",y[i].X,y[i].Y);
//                if(y[i].X<y[i-1].Y)
//                {
//                    fu=1;break;
//                }
//            }
//            if(fu==1)
//            {
//
//                printf("CONFLICT\n");
//                continue;
//            }
//            else
//                printf("NO CONFLICT\n");
//        }
//        else
//        {
//            for(i=2;i<=n;i++)
//            {
//                if(x[i].X<x[i-1].Y)
//                {
//                    fu=1;break;
//                }
//            }
//            if(fu==1)
//                printf("CONFLICT\n");
//            else
//                printf("NO CONFLICT\n");
//        }
    }
}
