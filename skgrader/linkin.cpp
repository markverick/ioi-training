#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
pair<double,double> p[510];
priority_queue<double> q;
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
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                continue;
            q.push(-dist(p[i].X,p[i].Y,p[j].X,p[j].Y));
        }
    }
    for(i=0;i<m;i++)
    {
        q.pop();
    }
    printf("%.2f",sqrt(-q.top()));
}
