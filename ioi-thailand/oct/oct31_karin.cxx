#include<bits/stdc++.h>
using namespace std;
int n,m,p;
int dx[8]={0,0,1,1,1};
int dy[8]={-1,1,-1,0,1};
int mat[35][8];
vector<int> v,zero;
vector<int> Pow(vector<int> base,int p)
{
    int i,j,tmp;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            base[(j+1)%m]=min(base[(j+1)%m],base[j]+mat[j][1]);
            tmp=(j-1)<0?j-1+m:j-1;
            base[tmp]=min(base[tmp],base[j]+mat[j][0]);
        }
    }
    if(p==1)
    {
        return base;
    }
    vector<int> a=Pow(base,p/2),s=zero,b=zero,c[33];
    for(i=0;i<m;i++)
    {
        s[i]=0;
        c[i]=Pow(s,p/2);
        s[i]=1000000000;
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            b[i]=min(b[i],a[j]+c[j][i]+mat[j][3]);
            b[i]=min(b[i],a[j]+c[(j+1)%m][i]+mat[j][4]);
            b[i]=min(b[i],a[j]+c[(j-1)<0?j-1+m:j-1][i]+mat[j][2]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            b[(j+1)%m]=min(b[(j+1)%m],b[j]+mat[j][1]);
            tmp=(j-1)<0?j-1+m:j-1;
            b[tmp]=min(b[tmp],b[j]+mat[j][0]);
        }
    }
    if(p%2)
    {
        vector<int> d=zero;
        for(i=0;i<m;i++)
        {
            d[i]=min(d[i],b[i]+mat[i][3]);
            d[(i+1)%m]=min(d[(i+1)%m],b[i]+mat[i][4]);
            tmp=(i-1)<0?i-1+m:i-1;
            d[tmp]=min(d[tmp],b[i]+mat[i][2]);
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                d[(j+1)%m]=min(d[(j+1)%m],d[j]+mat[j][1]);
                tmp=(j-1)<0?j-1+m:j-1;
                d[tmp]=min(d[tmp],d[j]+mat[j][0]);
            }
        }
        return d;
    }
    return b;
}
int main()
{
    int i,j;
    scanf("%d %d %d",&n,&m,&p);
    for(i=0;i<m;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    v.emplace_back(0);
    for(i=1;i<m;i++)
        v.emplace_back(1000000000);
    for(i=0;i<m;i++)
        zero.emplace_back(1000000000);
    vector<int> out=Pow(v,n);
    printf("%d\n",out[p]);
}
