    #include<bits/stdc++.h>
    #define X first
    #define Y second
    using namespace std;
    vector<pair<int,int> > vec[100005];
    vector<int> blca;
    tuple<int,int,int> e[100005];
    int lca[20][200005],h[100005],wh[100005];
    int sub[100005],pa[100005],g[100005],jim[100005],ct;
    int val,point,n,seg[400005],x,y;
    void add(int l,int r,int idx)
    {
        if(l==r)
        {
            seg[idx]=val;
            return;
        }
        int mid=(l+r)/2;
        if(point<=mid)
            add(l,mid,idx*2);
        else
            add(mid+1,r,idx*2+1);
        seg[idx]=seg[idx*2]+seg[idx*2+1];
    }
    int sum(int l,int r,int idx)
    {
        if(x<=l&&r<=y) return seg[idx];
        if(x>r||y<l) return 0;
        int mid=(l+r)/2;
        return sum(l,mid,idx*2)+sum(mid+1,r,idx*2+1);
    }
    int dfs(int u,int p)
    {
        h[u]=h[p]+1;
        pa[u]=p;
        wh[u]= wh[u]==-1 ? blca.size() : wh[u];
        blca.push_back(u);
        sub[u]=1;
        for(int i=0;i<vec[u].size();i++)
            if(vec[u][i].X!=p)
            {
                sub[u]+=dfs(vec[u][i].X,u);
                blca.push_back(u);
            }
        return sub[u];
    }
    int buildhld(int u,int h,int cost)
    {
        if(h==-1) h=u;
        g[u]=h;
        jim[u]=ct++;
     
        point=jim[u];
        val=cost;
        add(0,n-1,1);
     
        int mc=-1,ind=-1;
        for(int i=0;i<vec[u].size();i++)
            if(vec[u][i].X!=pa[u])
                if(sub[vec[u][i].X]>mc)
                {
                    mc=sub[vec[u][i].X];
                    ind=i;
                }
        if(ind!=-1)
            buildhld(vec[u][ind].X,h,vec[u][ind].Y);
        for(int i=0;i<vec[u].size();i++)
            if(vec[u][i].X!=pa[u]&&i!=ind)
                buildhld(vec[u][i].X,-1,vec[u][i].Y);
     
    }
    int asklca(int x,int y)
    {
        x=wh[x];
        y=wh[y];
        if(x>y) swap(x,y);
        int k=log(y-x+1)/log(2);
        if(h[lca[k][x]]<h[lca[k][y-(1<<k)+1]])
            return lca[k][x];
        return lca[k][y-(1<<k)+1];
    }
    int chain(int u,int v)
    {
        int ss=0;
        while(g[u]!=g[v])
        {
            y=jim[u];
            x=jim[g[u]];
            ss+=sum(0,n-1,1);
            u=pa[g[u]];
        }
        y=jim[u];
        x=jim[v];
        x++;
        ss+=sum(0,n-1,1);
        return ss;
    }
    int main()
    {
        int i,j,u,v,w,q,op,a;
        scanf("%d",&n);
        memset(wh,-1,sizeof wh);
        ct=0;
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            e[i]=make_tuple(u,v,w);
            vec[u].emplace_back(v,w);
            vec[v].emplace_back(u,w);
        }
        dfs(1,1);
        for(i=0;i<blca.size();i++) lca[0][i]=blca[i];
        for(j=1;1<<j<=blca.size();j++)
        {
            for(i=0;i+(1<<j)-1<blca.size();i++)
            {
                if(h[lca[j-1][i]]>h[lca[j-1][i+(1<<(j-1))]])
                    lca[j][i]=lca[j-1][i+(1<<(j-1))];
                else
                    lca[j][i]=lca[j-1][i];
            }
        }
        buildhld(1,-1,0);
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            scanf("%d%d%d",&op,&u,&v);
            if(op==1)
            {
                j=u-1;
                val=v;
                tie(u,v,w)=e[j];
                if(pa[u]==v)
                    point=jim[u];
                else
                    point=jim[v];
                add(0,n-1,1);
            }
            else
            {
                a=asklca(u,v);
                printf("%d\n",chain(u,a)+chain(v,a));
            }
        }
    }
     