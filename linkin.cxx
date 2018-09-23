#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
pair<double,double> p[510];
int pa[510];
int hsh[510];
int find_(int v)
{
    while(pa[v]!=v)
    {
        v=pa[v];
    }
    return v;
}
void union_(int a,int b)
{
    a=find_(a);
    b=find_(b);
    if(rand()%2)
    {
        pa[b]=a;
    }
    else
    {
        pa[a]=b;
    }
    //printf("==%d %d\n",a,b);
    return;
}
double dist(double x1,double y1,double x2,double y2)
{
    return abs(x2-x1)*abs(x2-x1)+abs(y2-y1)*abs(y2-y1);
}
int main()
{
    srand(135);
    int n,i,j,k,m;
    scanf("%d %d",&m,&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf %lf",&p[i].X,&p[i].Y);
    }
    double mc=0;
    double fst=0,lst=10000,mid;
    int t=69;
    for(i=0;i<n;i++)
        pa[i]=i;
    while(t--)
    {
        mid=(fst+lst)/2;
        //printf("%f %f %f\n",fst,mid,lst);
        //system("pause");
        int fu=0;
        for(i=0;i<n;i++)
            pa[i]=i;
        for(i=0;i<n;i++)
        {
            int cot=0;
            for(j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                    //printf("%f %f\n",sqrt(dist(p[i].X,p[i].Y,p[j].X,p[j].Y)),mid);
                if(sqrt(dist(p[i].X,p[i].Y,p[j].X,p[j].Y))<=mid)
                {
                    union_(i,j);
                }
            }
            //printf("%d\n",cot);
        }
        set<int> st;
        for(i=0;i<n;i++)
        {
            st.insert(find_(i));
        }
        if(st.size()<=m)
        {
            lst=mid;
        }
        else
        {
            fst=mid;
        }
    }
    printf("%.2f\n",mid);
}
