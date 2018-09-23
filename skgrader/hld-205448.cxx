#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<int> ad[100135];
int x,y,sp[100135][50],state[100135],qs[100135],chain[100135],head[100135],w[100135],p[100135],cot[100135],posC[100135],pos[100135];
vector<int> order,h,hld;
void add(int a,int b)
{
    if(a>b)swap(a,b);
    qs[a]++;qs[b+1]--;
}
void dep(int idx)
{
    int i,sum=0,mc=0,id=idx;
    state[idx]=1;
    for(i=0;i<ad[idx].size();i++)
    {
        if(state[ad[idx][i]])
            continue;
        p[ad[idx][i]]=idx;
        ad[idx].emplace_back(ad[idx][i]);
        dep(ad[idx][i]);
        sum+=w[ad[idx][i]];
    }
    w[idx]=sum+1;
}
void dfs(int idx)
{
    int i,mc=0,id=idx;
    for(i=0;i<ad[idx].size();i++)
    {
        if(state[ad[idx][i]])
            continue;
        if(w[ad[idx][i]]>mc)
            mc=w[ad[idx][i]],id=ad[idx][i];
    }
    chain[id]=chain[idx];
    state[idx]=1;
    hld.emplace_back(idx);
    if(state[id]==0)
        dfs(id);
    for(i=0;i<ad[idx].size();i++)
    {
        if(state[ad[idx][i]]||ad[idx][i]==id)
            continue;
        dfs(ad[idx][i]);
    }
}
void def(int idx,int hi)
{
    int i;
    order.emplace_back(idx);
    h.emplace_back(hi);
    state[idx]=1;
    for(i=0;i<ad[idx].size();i++)
    {
        if(state[ad[idx][i]])
            continue;
        def(ad[idx][i],hi+1);
        order.emplace_back(idx);
        h.emplace_back(hi);
    }
    return;
}
int main()
{
    int n,m,i,j,k,a,b,lca,tmp,mc=0,sum=0,sz;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        chain[i]=i,p[i]=i;
    for(i=1;i<=n-1;i++)
    {
        scanf("%d %d",&a,&b);
        ad[a].emplace_back(b);
        ad[b].emplace_back(a);
    }
    dep(1);
    memset(state,0,sizeof state);
    dfs(1);
    memset(state,0,sizeof state);
    def(1,1);
    for(i=order.size()-1;i>=0;i--)
        pos[order[i]]=i;
    for(i=0;i<hld.size();i++)
        posC[hld[i]]=i;
    for(i=0;i<order.size();i++)
        sp[i][0]=i;
    for(j=1;(1<<j)<=h.size();j++)
    {
        for(i=0;i+(1<<j)<=h.size();i++)
        {
            if(h[sp[i][j-1]]<h[sp[i+(1<<(j-1))][j-1]])
                sp[i][j]=sp[i][j-1];
            else
                sp[i][j]=sp[i+(1<<(j-1))][j-1];
        }
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        x=pos[a];y=pos[b];
        if(x>y)swap(x,y);
        sz=(int)floor(log2(y-x+1));
        if(h[sp[x][sz]]<h[sp[y-(1<<(sz))+1][sz]])
            lca=order[sp[x][sz]];
        else
            lca=order[sp[y-(1<<(sz))+1][sz]];
        x=a;y=b;
        if(chain[x]!=chain[lca])
        {
            while(chain[x]!=chain[lca])
            {
                add(posC[x],posC[chain[x]]);
                x=p[chain[x]];
            }
        }
        if(chain[y]!=chain[lca])
        {
            while(chain[y]!=chain[lca])
            {
                add(posC[y],posC[chain[y]]);
                y=p[chain[y]];
            }
        }
        add(posC[x],posC[lca]);
        add(posC[y],posC[lca]);
        qs[posC[lca]]--;qs[posC[lca]+1]++;
    }
    mc=0;sum=0;
    for(i=0;i<=hld.size();i++)
        sum+=qs[i],mc=max(mc,sum);
    printf("%d",mc);
}
//135th line
