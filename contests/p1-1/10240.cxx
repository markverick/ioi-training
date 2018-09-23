#include<bits/stdc++.h>
using namespace std;
double a[7],b[7];
int hsh[7];
int main()
{
    double x,y,xa,ya,xb,yb;
    int i,j,k,fu;
    while(scanf("%lf %lf",&a[1],&b[1])!=EOF)
    {
        fu=0;
        memset(hsh,0,sizeof hsh);
        for(i=2;i<=4;i++)
        {
            scanf("%lf %lf",&a[i],&b[i]);
        }
        for(i=1;i<=4;i++)
        {
            for(j=i+1;j<=4;j++)
            {
                if(a[i]==a[j]&&b[i]==b[j])
                {
                    x=a[i];y=b[i];
                    hsh[i]=1;hsh[j]=1;
                    fu=1;break;
                }
            }
            if(fu==1)break;
        }
        k=0;
        for(i=1;i<=4;i++)
        {
            if(hsh[i])
                continue;
            if(k==0)
            {
                xa=a[i];ya=b[i];
                k++;
            }
            else
            {
                xb=a[i];yb=b[i];
            }
        }
//        printf("%.3f %.3f %.3f %.3f %.3f %.3f\n",x,y,xa,ya,xb,yb);
        printf("%.3lf %.3lf\n",x+xa+xb-2*x,y+ya+yb-2*y);
    }
}
