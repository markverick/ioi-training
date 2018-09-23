#include<bits/stdc++.h>
using namespace std;
int ls[2600][55],maps[55][55],hsh[2600];
int main()
{
    int t,T,i,j,k,mn,n,l;
    vector<int> x,y;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        memset(maps,0,sizeof maps);
        memset(hsh,0,sizeof hsh);
        memset(ls,0,sizeof ls);
        mn=1000000000;
        scanf("%d",&n);
        for(i=1;i<=2*n-1;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&ls[i][j]);
            }
        }
        for(i=1;i<=2*n-1;i++)
        {
            mn=min(mn,ls[i][1]);
        }
        vector<int> tm;
        for(i=1;i<=2*n-1;i++)
        {
            if(ls[i][1]==mn)
            {
                tm.emplace_back(i);
            }
        }
        for(i=1;i<=n;i++)
        {
            maps[1][i]=ls[tm[0]][i];
            maps[i][1]=ls[tm[1]][i];
        }
        for(i=2;i<=n;i++)
        {
            for(j=1;j<=n*2-1;j++)
            {
                if(hsh[j])
                    continue;
                for(k=1;k<i;k++)
                {
                    if(maps[k][i]!=ls[j][k])
                        break;
                }
                if(k!=i)
                {
                    continue;
                }
                for(k=i;k<=n;k++)
                {
                    if(maps[k][i-1]>=ls[j][k])
                        break;
                }
                if(k==n+1)
                {
                    x.emplace_back(j);
                }
            }
            for(j=1;j<=n*2-1;j++)
            {
                if(hsh[j])
                    continue;
                for(k=1;k<i;k++)
                {
                    if(maps[i][k]!=ls[j][k])
                        break;
                }
                if(k!=i)
                {
                    continue;
                }
                for(k=i;k<=n;k++)
                {
                    if(maps[i-1][k]>=ls[j][k])
                        break;
                }
                if(k==n+1)
                {
                    y.emplace_back(j);
                }
            }
            for(j=0;j<x.size();j++)
            {
                for(k=0;k<y.size();k++)
                {
                    if(x[j]==y[k])
                        continue;
                    if(ls[x[j]][i]==ls[y[k]][i])
                    {
                        hsh[x[j]]=1;
                        hsh[y[k]]=1;
                        for(l=i;l<=n;l++)
                        {
                            maps[l][i]=ls[x[j]][l];
                        }
                        for(l=i;l<=n;l++)
                        {
                            maps[i][l]=ls[y[k]][l];
                        }
                        break;
                    }
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                printf("%d ",maps[i][j]);
            }
            printf("\n");
        }
    }
}

