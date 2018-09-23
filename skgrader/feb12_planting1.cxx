#include<bits/stdc++.h>
#define EB emplace_back
using namespace std;

vector<int> vx;
vector<int> vy;
int n,xa[35],ya[35],xb[35],yb[35];
int a[35];
int hsh[35][35];
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&xa[i],&yb[i],&xb[i],&ya[i]);
        vx.EB(xa[i]);
        vx.EB(xb[i]);
        vy.EB(ya[i]);
        vy.EB(yb[i]);
    }
//    vx.EB(-100000);
//    vy.EB(-100000);
//    vx.EB(100000);
//    vy.EB(100000);
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    auto it= unique (vx.begin(), vx.end());
    vx.resize( distance(vx.begin(),it) );
    auto it2= unique (vy.begin(), vy.end());
    vy.resize( distance(vy.begin(),it2) );
    for(i=1;i<=n;i++)
    {
        for(j=0;j<vx.size();j++)
        {
            if(vx[j]>=xa[i]&&vx[j]<xb[i])
            {
                for(k=0;k<vy.size();k++)
                {
                    if(vy[k]>=ya[i]&&vy[k]<yb[i])
                    {
                        //printf("F");
                        hsh[j][k]=1;
                    }
                }
            }
        }
    }
    int sum=0;
    for(i=0;i<vx.size()-1;i++)
    {
        for(j=0;j<vy.size()-1;j++)
        {
            if(hsh[i][j]==1)
            {
                sum+=(vx[i+1]-vx[i])*(vy[j+1]-vy[j]);
            }
        }
    }
    printf("%d",sum);
}
