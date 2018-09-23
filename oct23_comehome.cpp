#include<bits/stdc++.h>
using namespace std;
int d[150][150];
char a[5],b[5],out;
vector<pair<int,int> > adj[150];
int main()
{
    int n,m,i,j,k,c,mn=1000000000;
    scanf("%d",&m);
    for(i=0;i<=140;i++)
    {
        for(j=0;j<=140;j++)
            d[i][j]=1000000000;
        d[i][i]=0;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%s %s %d",a,b,&c);
        d[a[0]][b[0]]=min(d[a[0]][b[0]],c);d[b[0]][a[0]]=min(d[b[0]][a[0]],c);
    }
    for(k='A';k<='z';k++)
        for(i='A';i<='z';i++)
            for(j='A';j<='z';j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    for(i='A';i<'Z';i++)
    {
        if(mn>d[i]['Z'])
        {
            mn=d[i]['Z'];
            out=i;
        }
    }
    printf("%c %d",out,mn);
}
