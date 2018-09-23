#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<pair<int,int> > adx[200135],adt[200135];
pair<int,int> adj[200135];
int state[200135],G,gnai[200135],indeg[200135],base[200135],cot=0;
vector<int> grp[200135];
void dfs(int idx)
{
    gnai[idx]=G;
    grp[G].emplace_back(idx);
    for(int i=0;i<adx[idx].size();i++)
    {
        if(gnai[adx[idx][i].X])
            continue;
        dfs(adx[idx][i].X);
    }
}
int fcyc(int idx)
{
    state[idx]=1;
    if(state[adj[idx].X])
    {
        while(state[idx]==1)
        {
            state[idx]=2;
            idx=adj[idx].X;
        }
        return idx;
    }
    return fcyc(adj[idx].X);
}
void dep(int idx)
{
    int sum=0;
    for(int i=0;i<adt[idx].size();i++)
    {
        if(state[adt[idx][i].X]==2)continue;
        dep(adt[idx][i].X);
        sum+=adt[idx][i].Y;
    }
    base[idx]=sum;
    if(state[idx]!=2&&sum<adj[idx].Y)
        cot+=adj[idx].Y-sum;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,a,b,x,fst,lst                                           ;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        adj[i]=MP(a,b);
        indeg[a]+=b;
        adx[a].emplace_back(i,b);
        adx[i].emplace_back(a,b);
        adt[a].emplace_back(i,b);
    }
    G=0;
    for(i=1;i<=n;i++)
    {
        if(gnai[i])continue;
        G++;
        dfs(i);
    }
    cot=0;
    int all,mn=MI;
//    printf("%d\n",cot);
    for(i=1;i<=G;i++)
    {
        all=0;
        mn=MI;
        fcyc(grp[i][0]);
        for(j=0;j<grp[i].size();j++)
        {
            if(state[grp[i][j]]==2)
            {
                dep(grp[i][j]);
            }
        }
        for(j=0;j<grp[i].size();j++)
        {
            if(state[grp[i][j]]==2)
            {
                if(base[grp[i][j]]>=adj[grp[i][j]].Y)
                {
                    indeg[grp[i][j]]-=adj[grp[i][j]].Y;
                    base[grp[i][j]]-=adj[grp[i][j]].Y;adj[grp[i][j]].Y=0;
                }
                all+=max(0,adj[grp[i][j]].Y-indeg[grp[i][j]]);
            }
        }
//        printf("branch = %d\n",cot);
//        printf("all = %d\n",all);
        for(j=0;j<grp[i].size();j++)
        {
            if(state[grp[i][j]]==2)
            {
//                printf("!%d\n",adj[grp[i][j]].Y);
                mn=min(mn,all+max(0,adj[grp[i][j]].Y-base[grp[i][j]])-max(0,adj[grp[i][j]].Y-indeg[grp[i][j]]));
            }
        }
        cot+=mn;
//        printf("%d\n",mn);
    }
    printf("%d",cot);
//    for(i=1;i<=n;i++)
//    {
//        if(state[i]==2)
//            printf("[%d] = %d\n",i,base[i]);
//    }
//    printf("%d\n",cot);
}
