#include<bits/stdc++.h>
using namespace std;
int n;
int S[10135],M[10135],SS[10135];
int P[10135],cot=1;
int Free[10135];
queue<int> q;
vector<int> adj[10135];
int Cut(int x)
{
    int i,tot=S[x];
    for(i=0;i<adj[x].size();i++)
    {
        if(Free[adj[x][i]]==0)
        {
            tot+=SS[adj[x][i]];
        }
    }
    for(i=0;i<adj[x].size();i++)
    {
        if(SS[adj[x][i]]>=tot-SS[adj[x][i]])
        {
            Free[adj[x][i]]=1;
            cot++;
        }
    }
}
int Find(int x)
{
    while(P[x]!=x)
    {
        x=P[x];
    }
    return x;
}
int Fill(int x)
{
    //printf("%d\n",x);
    if(adj[x].size()==0)
    {
        SS[x]=S[x];
        return S[x];
    }
    int i;
    int sum=S[x];
    for(i=0;i<adj[x].size();i++)
    {
        sum+=Fill(adj[x][i]);
    }
    SS[x]=sum;
    return sum;
}
int main()
{
    int i,j,k,a;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        P[i]=i;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%*d %d %d",&S[i],&M[i]);
        for(j=1;j<=M[i];j++)
        {
            scanf("%d",&a);
            adj[i].emplace_back(a);
            P[a]=i;
        }
    }
    int head=Find(1),u;
    Fill(head);
    q.emplace(head);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        Cut(u);
        for(i=0;i<adj[u].size();i++)
        {
            q.emplace(adj[u][i]);
        }
    }
    Free[head]=1;
    printf("%d\n",cot);
    for(i=1;i<=n;i++)
    {
        if(Free[i]==1)
        {
            printf("%d\n",i);
        }
    }

}
