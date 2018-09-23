#include<bits/stdc++.h>
using namespace std;
int v[6500];
vector<int> adj[6500];
vector<int> adi[6500];
queue<int> q;
int hsh[6500];
int jum[6500][3];
int dp(int idx,bool got)
{
    if(jum[idx][got]!=-1000000000)
        return jum[idx][got];
    if(adi[idx].size()==0)
        return 0;
    int mc=0;
    int i;
    if(got==0)
    {
        for(i=0;i<adi[idx].size();i++)
        {
            mc+=max(dp(adi[idx][i],false),dp(adi[idx][i],true)+v[adi[idx][i]]);
        }
    }
    else
    {
        for(i=0;i<adi[idx].size();i++)
        {
            mc+=dp(adi[idx][i],false);
        }
    }
    return jum[idx][got]=mc;
}

int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
    }
    for(i=0;i<=6000;i++)
    {
        for(j=0;j<3;j++)
        {
            jum[i][j]=-1000000000;
        }
    }
    int a,b;
    int s=-1;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        if(a==0&&b==0)
            break;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        s=a;
    }
    if(s==-1)
    {
        int sum=0;
        for(i=1;i<=n;i++)
        {
            if(v[i]<=0)
                continue;
            sum+=v[i];
        }

        printf("%d",sum);
        exit(0);
    }
    hsh[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(i=0;i<adj[x].size();i++)
        {
            if(hsh[adj[x][i]]==1)
                continue;
            hsh[adj[x][i]]=1;
            adi[x].emplace_back(adj[x][i]);
            q.push(adj[x][i]);
        }
    }
    /*for(i=1;i<=n;i++)
    {
        printf("[%d] = ",i);
        for(j=0;j<adi[i].size();j++)
        {
            printf("%d ",adi[i][j]);
        }
        printf("\n");
    }*/
    printf("%d",max(dp(s,false),dp(s,true)+v[s]));
}
