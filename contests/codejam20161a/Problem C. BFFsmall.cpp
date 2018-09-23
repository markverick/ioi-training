#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[13],adt[13];
int jum[2000][13][13];
int dp(int bit,int st,int idx,int noob)
{
    int i;
    if(bit!=0&&idx==st&&noob==0)
    {
        return 0;
    }
    int mc=-1000000000,v;
    if(noob==1)
    {
        for(i=1;i<=n;i++)
        {
            v=i;
            if((bit|(1<<(v-1)))==bit)
                continue;
            mc=max(mc,dp(bit|(1<<(v-1)),st,v,0)+1);
        }
    }
    else
    {
        for(i=0;i<adj[idx].size();i++)
        {
            v=adj[idx][i];
            if((bit|(1<<(v-1)))==bit)
                continue;
            mc=max(mc,dp(bit|(1<<(v-1)),st,v,1)+1);
        }
        for(i=0;i<adt[idx].size();i++)
        {
            v=adt[idx][i];
            if((bit|(1<<(v-1)))==bit)
                continue;
            mc=max(mc,dp(bit|(1<<(v-1)),st,v,0)+1);
        }
    }
    return mc;
}
int main()
{
    int t,T,i,j,k,a;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    int mc=0;
    for(t=1;t<=T;t++)
    {
        mc=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            adj[i].clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            adj[i].emplace_back(a);
            adt[a].emplace_back(i);
        }
        for(i=1;i<=n;i++)
        {
            memset(jum,-1,sizeof jum);
            mc=max(mc,dp(0,i,i,0));
            printf("\n");
        }
        printf("Case #%d: %d\n",t,mc);
    }
}


