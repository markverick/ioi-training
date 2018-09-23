#include<bits/stdc++.h>
using namespace std;
int n,k;
int maps[20][20];
vector<int> x,y;
int qs[20][20];
int result[20];
int mn=1000000000;
inline void gen(int idx,int cut)
{
    int i,j;
    if(idx>2*n-2)
    {
        if(cut==k)
        {
            int mc=0;
            x.clear();y.clear();
            x.emplace_back(0);
            y.emplace_back(0);
            for(i=1;i<=n-1;i++)
            {
                if(result[i]==1)
                    x.emplace_back(i);
            }
            for(i=n;i<=n*2-2;i++)
            {
                if(result[i]==1)
                    y.emplace_back(1+i-n);
            }
            x.emplace_back(n);
            y.emplace_back(n);
           // printf("%d %d\n",x.size(),y.size());
            for(i=1;i<x.size();i++)
            {
                for(j=1;j<y.size();j++)
                {
                    mc=max(mc,qs[x[i]][y[j]]-qs[x[i]][y[j-1]]-qs[x[i-1]][y[j]]+qs[x[i-1]][y[j-1]]);
                }
            }
            //printf("%d\n",mc);
            mn=min(mn,mc);
            return;
        }
        return;
    }
    if(2*n-2-idx>=k-cut)
    {
        result[idx]=0;
        gen(idx+1,cut);
    }
    if(k-cut>0)
    {
        result[idx]=1;
        gen(idx+1,cut+1);
    }
}
int main()
{
    int i,j;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&maps[i][j]);
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+maps[i][j];
        }
    }
    gen(1,0);
    printf("%d",mn);
}
