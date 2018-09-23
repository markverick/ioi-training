#include<bits/stdc++.h>
using namespace std;
int ls[2600][55],maps[55][55],nai[2600];
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
        memset(nai,0,sizeof nai);
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
            for(j=2;j<=n;j++)
            {
                x.clear();y.clear();
                for(k=1;k<=n*2-1;k++)
                {
                    if(nai[k]==0||nai[k]==n+j)
                    {
                        for(l=1;l<i;l++)
                        {
                            if(ls[k][l]!=maps[l][j])
                                break;
                        }
                        if(l==i)
                        {
                            x.emplace_back(k);
                        }
                    }
                    if(nai[k]==0||nai[k]==i)
                    {
                        for(l=1;l<j;l++)
                        {
                            if(ls[k][l]!=maps[i][l])
                                break;
                        }
                        if(l==j)
                        {
                            y.emplace_back(k);
                        }
                    }
                }
                for(k=0;k<x.size();k++)
                {
                    for(l=0;l<y.size();l++)
                    {
                        if(x[k]==y[l])
                            continue;
                        if(ls[x[k]][i]==ls[y[l]][j])
                        {
                            nai[x[k]]=n+j;nai[y[l]]=i;
                            maps[i][j]=ls[x[k]][i];
                            break;
                        }
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
        printf("%d\n",nai[4]);
    }
}

