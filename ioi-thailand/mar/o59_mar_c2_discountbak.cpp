#include<bits/stdc++.h>
#define MP make_pair
#define X first
#define Y second
using namespace std;
vector<long long> ad[100135];
vector<tuple<long long,long long,long long> > edge;
vector<pair<long long,long long> > ADJ[100135];
map<pair<long long,long long>,long long> adj;
long long x,y,sp[100135][50],Max[100135],hsh[100135],deg[100135],cost[100135],P[100135],H[100135],state[100135],qs[100135],chain[100135],head[100135],w[100135],p[100135],cot[100135],posC[100135],pos[100135];
vector<long long> order,h,hld;
long long Find(long long idx)
{
    while(P[idx]!=idx)
    {
        idx=P[idx];
    }
    return idx;
}
void Union(long long x,long long y)
{
    x=Find(x);
    y=Find(y);
    if(H[x]>=H[y])
    {
        P[y]=x;
        H[x]=max(H[x],H[y]+1);
    }
    else
    {
        P[x]=y;
        H[y]=max(H[y],H[x]+1);
    }
}
void dep(long long idx)
{
    long long i,sum=0,mc=0,id=idx;
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
void dfs(long long idx)
{
    long long i,mc=0,id=idx;
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
void def(long long idx,long long hi)
{
    long long i;
    order.emplace_back(idx);
    h.emplace_back(hi);
    state[idx]=1;
    if(head[chain[idx]]==0)
        head[chain[idx]]=idx;
    for(i=0;i<ad[idx].size();i++)
    {
        if(state[ad[idx][i]])
            continue;
        deg[idx]++;
        if(chain[idx]==chain[ad[idx][i]])
            Max[chain[idx]]=max(Max[chain[idx]],adj[make_pair(idx,ad[idx][i])]);
        qs[ad[idx][i]]=qs[idx]+adj[make_pair(idx,ad[idx][i])];
        def(ad[idx][i],hi+1);
        order.emplace_back(idx);
        h.emplace_back(hi);
    }
    return;
}
int main()
{
    long long N,M,n,m,i,j,k,a,b,c,lca,mc=0,sum=0,sz;
    scanf("%lld %lld",&N,&M);
    for(i=1;i<=N;i++)
        P[i]=i;
    for(i=1;i<=M;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        a++;b++;
        ADJ[a].emplace_back(b,c);
        ADJ[b].emplace_back(a,c);
        edge.emplace_back(c,a,b);
    }
    sort(edge.begin(),edge.end());
    for(i=0;i<edge.size();i++)
    {
        tie(c,a,b)=edge[i];
        if(Find(a)!=Find(b))
        {
            sum+=c;
            hsh[i]=1;
            adj[make_pair(a,b)]=c;
            adj[make_pair(b,a)]=c;
            ad[a].emplace_back(b);
            ad[b].emplace_back(a);
            Union(a,b);
        }
    }
    n=N;
    for(i=1;i<=n;i++)
        chain[i]=i,p[i]=i;
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
    for(i=0;i<edge.size();i++)
    {
        tie(c,a,b)=edge[i];
        if(chain[a]==chain[b])
            cost[chain[a]]++;
    }
//    system("pause");
    sum=0;
    long long mn=1000000000000000000,tmp,mc1,mc2,tm;
    for(i=0;i<edge.size();i++)
    {
        mc1=0;mc2=0;
        if(hsh[i])
            continue;
        sum=0;
        tie(c,a,b)=edge[i];
        x=pos[a];y=pos[b];
        if(x>y)swap(x,y);
        sz=(long long)floor(log2(y-x+1));
        if(h[sp[x][sz]]<h[sp[y-(1<<(sz))+1][sz]])
            lca=order[sp[x][sz]];
        else
            lca=order[sp[y-(1<<(sz))+1][sz]];
        x=a;y=b;
        if(chain[x]!=chain[lca])
        {
            while(chain[x]==chain[a])
            {
                mc1=max(mc1,adj[MP(x,p[x])]);
                x=p[x];
            }
            while(chain[x]!=chain[lca])
            {
                mc1=max(mc1,Max[chain[x]]);
                mc1=max(mc1,adj[make_pair(head[chain[x]],p[head[chain[x]]])]);
                sum+=qs[x]-qs[p[head[chain[x]]]];
//                sum+=cost[chain[x]]+adj[make_pair(head[chain[x]],p[chain[x]])];
                x=p[chain[x]];
            }
            tm=x;
            while(x!=lca)
            {
                mc1=max(mc1,adj[make_pair(x,p[x])]);
                x=p[x];
            }
            x=tm;
        }
        else
        {
            while(x!=lca)
            {
                mc1=max(mc1,adj[MP(x,p[x])]);
                x=p[x];
            }
            x=a;
        }
        if(chain[y]!=chain[lca])
        {
            while(chain[y]==chain[b])
            {
                mc2=max(mc2,adj[MP(y,p[y])]);
                y=p[y];
            }
            while(chain[y]!=chain[lca])
            {
                mc2=max(mc2,Max[chain[y]]);
                mc2=max(mc2,adj[make_pair(head[chain[y]],p[head[chain[y]]])]);
                sum+=qs[y]-qs[p[head[chain[y]]]];
//                sum+=cost[chain[y]]+adj[make_pair(head[chain[y]],p[chain[y]])];
                y=p[chain[y]];
            }
            tm=y;
            while(y!=lca)
            {
                mc2=max(mc2,adj[make_pair(y,p[y])]);
                y=p[y];
            }
            y=tm;
        }
        else
        {
            while(y!=lca)
            {
                mc2=max(mc2,adj[make_pair(y,p[y])]);
                y=p[y];
            }
            y=b;
        }

        sum+=qs[x]+qs[y]-2*qs[lca];
//        printf("%lld %lld\n",x,y,lca);
//        printf("%lld %lld\n",mc1,mc2);
        tmp=sum-max(mc1,mc2)+c;
//        printf("%lld -> %lld = Before: %lld After: %lld (%lld) >> %lld\n",a-1,b-1,sum,tmp,c,tmp+1-sum);
        if(tmp-sum+1<=c&&tmp-sum+1>=0)
            mn=min(mn,tmp+1-sum);
    }
    printf("%lld",mn);
}
