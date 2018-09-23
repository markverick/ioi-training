void dfs(int u,int p)
{
    p[u]=u;A[u]=u;
    for(i=0;i<adj[u].size();i++)
    {
        if(adj[u][i]==p)
        {
            dfs(adj[u][i],u);
            Union(u,v)
            A[Find(u)]=u;
        }
    }
    color[u]=1;
    for(i=0;i<lca[u].size();i++)
    {
        if(color[lca[u][i].X]==1)
            out[lca[u][i].Y]=A[Find(lca[u][i].X)];
    }
}

