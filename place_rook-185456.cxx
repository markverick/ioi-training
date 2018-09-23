#include<bits/stdc++.h>
using namespace std;
int r,c,n,adj[633][633],state[633],chk;
int result[633];
void dfs(int idx,int cot)
{
    int i;
    if(idx==r+c+1)
    {
        for(i=1;i<cot;i++)
        {
            adj[result[i-1]][result[i]]=0;
            adj[result[i]][result[i-1]]=1;
        }
        chk=1;
//        for(i=0;i<cot;i++)
//            printf("%d ->",result[i]);
//        printf("END\n");
        return;
    }
    state[idx]=1;
    for(i=0;i<=r+c+1;i++)
    {
        if(state[i]||adj[idx][i]<=0)
            continue;
        result[cot]=i;
        dfs(i,cot+1);
        if(chk==1)
            return;
    }
}
int main()
{
    int T,a,b,i,j;
    while(scanf("%d %d %d",&r,&c,&n)!=EOF)
    {
        memset(adj,0,sizeof adj);
        for(i=1;i<=r;i++)
            for(j=r+1;j<=r+c;j++)
                adj[i][j]=1;
        for(i=1;i<=r;i++)
            adj[0][i]=1;
        for(i=r+1;i<=r+c;i++)
            adj[i][r+c+1]=1;
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&a,&b);
            a++;b++;
            adj[a][r+b]=0;
        }
        chk=1;
        result[0]=0;
        while(chk==1)
        {
            memset(state,0,sizeof state);
            chk=0;
            dfs(0,1);
        }
        int sum=0;
        for(i=r+1;i<=r+c;i++)
        {
            sum+=adj[r+c+1][i];
        }
        printf("%d\n",sum);
    }
}
