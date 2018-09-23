#include<bits/stdc++.h>
using namespace std;
vector<int> adj[30];
int state[530000][21],result[30],n,cot=0;
int d[30][30];
void dfs(int bit,int idx,int R)
{
    int i;
    if(idx==n)
    {
        for(i=1;i<=R;i++)
        {
            printf("%d",result[i]);
            if(i<R)
                printf(" ");
        }
        printf("\n");
        cot++;
        return;
    }
    if(d[idx][n]==1000000000)
        return;
    for(i=0;i<adj[idx].size();i++)
    {
        if(adj[idx][i]==1)
            continue;
        if((bit|(1<<adj[idx][i]-2))==bit)
            continue;
        if(state[bit|(1<<adj[idx][i]-2)][adj[idx][i]])
            continue;
        state[bit|(1<<adj[idx][i]-2)][adj[idx][i]]=1;
        result[R+1]=adj[idx][i];
        dfs(bit|(1<<adj[idx][i]-2),adj[idx][i],R+1);
        state[bit|(1<<adj[idx][i]-2)][adj[idx][i]]=0;
    }
}
int main()
{
//    freopen("out.txt","w",stdout);
    int i,j,k,a,b,T=0;
    while(scanf("%d",&n)!=EOF)
    {
        T++;cot=0;
        printf("CASE %d:\n",T);
        memset(state,0,sizeof state);
        memset(result,0,sizeof result);
        for(i=0;i<=20;i++)
            adj[i].clear();
        for(i=0;i<=20;i++)
        {
            for(j=0;j<=20;j++)
            {
                d[i][j]=1000000000;
            }
        }
        for(i=0;i<=20;i++)
            d[i][i]=0;
        while(scanf("%d %d",&a,&b)!=EOF)
        {
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
            d[a][b]=1;
            d[b][a]=1;
            if(a==0&&b==0)
                break;
        }
        for(k=0;k<=20;k++)
            for(i=0;i<=20;i++)
                for(j=0;j<=20;j++)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        for(i=1;i<=20;i++)
        {
            sort(adj[i].begin(),adj[i].end());
        }
        result[1]=1;
        dfs(0,1,1);
        printf("There are %d routes from the firestation to streetcorner %d.\n",cot,n);
    }
}
