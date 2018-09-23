#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int p[200135],ste[200135];
vector<int> adj[200135];
int dfs(int idx,int pa)
{
    int mc=0,i;
    ste[idx]=1;
    for(i=0;i<adj[idx].size();i++)
    {
        if(p[adj[idx][i]]==adj[idx][i]||adj[idx][i]==pa)
            continue;
        if(ste[adj[idx][i]])
        {
            if(p[idx]==adj[idx][i])
                return idx;
            else if(p[adj[idx][i]]==idx)
                return adj[idx][i];
            else
            {
                while(1)
                {
                    printf("YOLO\n");
                }
            }

        }
        mc=max(mc,dfs(adj[idx][i],idx));
    }
    return mc;
}
int main()
{
    int n,i,j,k,ye=0,cot=0,root;
    vector<int> v;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    for(i=1;i<=n;i++)
    {
        if(p[i]!=i)
        {
            adj[i].emplace_back(p[i]);
            adj[p[i]].emplace_back(i);
        }
        else
            ye++,root=i;
    }
    int tmp;
    if(ye==0)
    {
        for(i=1;i<=n;i++)
        {
            if(p[i]!=i&&ste[i]==0)
            {
                tmp=dfs(i,0);
                if(tmp)
                    cot++,v.emplace_back(tmp);
//              printf("!%d\n",cot);
            }
        }
        printf("%d\n",cot);
        p[v[0]]=v[0];
        root=v[0];
        for(i=1;i<v.size();i++)
        {
            p[v[i]]=root;
        }
        for(i=1;i<=n;i++)
        {
            printf("%d ",p[i]);
        }
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        if(p[i]!=i&&ste[i]==0)
        {
            tmp=dfs(i,0);
            if(tmp)
                cot++,v.emplace_back(tmp);
//            printf("!%d\n",cot);
        }
    }
    for(i=0;i<v.size();i++)
    {
        p[v[i]]=root;
    }
    for(i=1;i<=n;i++)
    {
        if(p[i]==i&&i!=root)
        {
            p[i]=root;
        }
    }
//    printf("%d %d\n",ye,cot);
    printf("%d\n",ye-1+cot);
    for(i=1;i<=n;i++)
    {
        printf("%d ",p[i]);
    }
}
