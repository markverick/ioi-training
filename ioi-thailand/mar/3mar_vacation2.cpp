#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int,int> > adj[21000];
vector<pair<int,int> > jda[21000];
int inted[21000];
int id[220];
int dist[220][21000];
int distK[220][21000];
int main()
{
    int n,m,kk,q;
    scanf("%d %d %d %d",&n,&m,&kk,&q);
    int i,j,k;
    for(i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].emplace_back(b,c);
        //jda[b].emplace_back(a,c);
    }
    for(i=0;i<kk;i++)
    {
        scanf("%d",&id[i]);
        inted[id[i]]=1;
    }
    /*for(i=0;i<kk;i++)
    {
        for(j=0;j<kk;j++)
        {
            dist[i][j]=9999999999;
        }
        dist[i][i]=0;
    }*/
    printf("THIS IS TESTING TIMING PROGRAM!\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<adj[i].size();j++)
        {
            //if(dist[i][adj[i][j].X]>adj[i][j].Y+)
            //dist[i][adj[i][j].X]=adj[i][j].Y;
            printf("%d\n",adj[i][j].Y);
        }
    }
    //system("pause");
    for(i=0;i<q;i++)
    {
        int a;
        scanf("%d",a);
        printf("TEST");
    }

}
