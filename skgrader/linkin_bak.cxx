#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
pair<double,double> p[510];
double dist(double x1,double y1,double x2,double y2)
{
    return abs(x2-x1)*abs(x2-x1)+abs(y2-y1)*abs(y2-y1);
}
int main()
{
    int n,i,j,k,m;
    scanf("%d %d",&m,&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf %lf",&p[i].X,&p[i].Y);
    }
    double mc=0;
    double fst=0,lst=10000,mid;
    int t=360;
    while(t--)
    {
        mid=(fst+lst)/2;
        printf("%f %f %f\n",fst,mid,lst);
        system("pause");
        int fu=0;
        for(i=0;i<n;i++)
        {
            int cot=0;
            for(j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                    printf("%f %f\n",sqrt(dist(p[i].X,p[i].Y,p[j].X,p[j].Y)),mid);
                if(sqrt(dist(p[i].X,p[i].Y,p[j].X,p[j].Y))<=mid)
                    cot++;
            }
            //printf("%d\n",cot);
            if(cot>=m)
            {
                fu=1;
                break;
            }
        }
        if(fu==1)
        {
            lst=mid;
        }
        else
        {
            fst=mid;
        }
    }
    printf("%f %f %f\n",fst,mid,lst);
}
