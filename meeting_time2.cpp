#include<bits/stdc++.h>
#define INF 1073741820
using namespace std;
int u[5000],v[5000],s[5000],t[5000];
int ds[120][120];
int dt[120][120];
vector<pair<int,int> > ajs[106];
vector<pair<int,int> > ajt[106];
//vertex,weight
set<int> jums;
set<int> jumt;
int n,m;
int main()
{
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            ds[i][j]=INF;
            dt[i][j]=INF;
        }
    }
    for(i=1;i<=n;i++)
    {
        ds[i][i]=0;
        dt[i][i]=0;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d %d",&u[i],&v[i],&s[i],&t[i]);
        ajs[u[i]].push_back(make_pair(v[i],s[i]));
        ajt[u[i]].push_back(make_pair(v[i],t[i]));
        ds[u[i]][v[i]]=s[i];
        dt[u[i]][v[i]]=t[i];
    }


    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            for(k=1;k<=n;k++)
            {
                if(i==1&&k==n)
                {
                    jums.insert(ds[i][k]);
                    printf("%d\n",ds[i][k]);
                }
                if(ds[i][k]>ds[i][j]+ds[j][k])
                {
                    ds[i][k]=ds[i][j]+ds[j][k];

                }

            }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            for(k=1;k<=n;k++)
            {
                if(i==1&&k==n)
                {
                    jumt.insert(dt[i][k]);
                    printf("%d\n",dt[i][k]);
                }
                if(dt[i][k]>dt[i][j]+dt[j][k])
                {
                    dt[i][k]=dt[i][j]+dt[j][k];

                }


            }
    for(i=0;i<12000;i++)
    {
        printf("%d %d\n",*jums.lower_bound(i),*jumt.lower_bound(i));
        //system("pause");
        if(jums.lower_bound(i)==jums.end()||jumt.lower_bound(i)==jumt.end())
            break;
        if(*jums.lower_bound(i)==*jumt.lower_bound(i))
        {
            printf("%d",*jums.lower_bound(i));
            exit(0);
        }

    }
    printf("IMPOSSIBLE");

}
