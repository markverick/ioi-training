#include<bits/stdc++.h>
#define MP make_pair
#define X first
#define Y second
using namespace std;
int a[10000];
vector<pair<int,int> > hsh[1000135];
int main()
{
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]+a[j]<=m&&hsh[m-a[i]-a[j]].size()<3)
                hsh[m-a[i]-a[j]].emplace_back(i,j);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]+a[j]>=m)
                continue;
            for(k=0;k<hsh[a[i]+a[j]].size();k++)
            {
                if(hsh[a[i]+a[j]][k]!=MP(0,0)&&hsh[a[i]+a[j]][k].X!=i&&hsh[a[i]+a[j]][k].Y!=i&&hsh[a[i]+a[j]][k].X!=j&&hsh[a[i]+a[j]][k].Y!=j)
                {
                    printf("%d\n%d\n%d\n%d",a[hsh[a[i]+a[j]][k].X],a[hsh[a[i]+a[j]][k].Y],a[i],a[j]);
                    exit(0);
                }
            }

        }
    }
    printf("0\n0\n0\n0");

}
