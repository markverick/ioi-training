#include<bits/stdc++.h>
using namespace std;
int a[5][100135];
int hsh[5][100135];
int jum[100135];
int col[100135];
queue<int> q;
vector<int> adj[5][100135];
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            hsh[i][a[i][j]]++;
            adj[i][a[i][j]].emplace_back(j);
        }
    }
    int cot=0;
    for(i=1;i<=n;i++)
    {
        cot=0;
        for(j=1;j<=3;j++)
        {
            if(hsh[j][i]==0)
                cot++;
        }
        if(cot>0&&cot<3)
        {
            q.emplace(i);
            jum[i]=1;
        }
    }
    int idx;cot=0;

    while(!q.empty())
    {
        idx=q.front();cot++;
        //jum[idx]=1;
        for(i=1;i<=3;i++)
        {
            for(j=0;j<adj[i][idx].size();j++)
            {
                if(col[adj[i][idx][j]]==1)continue;
                for(k=1;k<=3;k++)
                {
                    if(jum[adj[i][idx][j]]==1)
                        continue;
                    hsh[k][a[k][adj[i][idx][j]] ]--;
                    if(hsh[k][a[k][adj[i][idx][j]] ]==0)
                    {
                        jum[adj[i][idx][j]]=1;
                        q.emplace(adj[i][idx][j]);
                    }
                }
                col[adj[i][idx][j]]=1;
//                if(jum[adj[i][idx][j]]==1)
//                    continue;
            }
        }
        q.pop();
    }
    printf("%d\n",cot);
}
