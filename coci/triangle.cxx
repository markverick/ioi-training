#include<bits/stdc++.h>
#define EPS 0.000000000000001
using namespace std;
int x[1511],y[1511];
vector<double> ang;
int main()
{
	int i,j,k,n;
	double cir=acos(-1.0)*2,fck;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
        scanf("%d %d",&x[i],&y[i]);
    int sum=0;
    for(i=1;i<=n;i++)
    {
        ang.clear();
        for(j=1;j<=n;j++)
        {
            if(j==i)continue;
            ang.emplace_back(atan2(x[j]-x[i],y[j]-y[i]));
        }
        sort(ang.begin(),ang.end());
        for(j=0;j<ang.size();j++)
        {
            if(ang[j]>cir/4+EPS)break;
            ang.emplace_back(ang[j]+cir);
        }
        for(j=1;j<=n;j++)
        {
            if(i==j)continue;
            fck=atan2(x[j]-x[i],y[j]-y[i]);
            sum+=upper_bound(ang.begin(),ang.end(),fck+cir/4+EPS)-lower_bound(ang.begin(),ang.end(),fck+cir/4-EPS);
        }
    }
    printf("%d",sum);
}
