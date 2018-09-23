#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int mat[2135][2135],state[2135],path[2135],fk,n,a[1135],b[1135];
vector<int> x,y;
unordered_map<int,int> mx,my;
void dfs(int idx,int C)
{
    int i;
    if(idx==n*2+1)
    {
        for(i=1;i<C;i++)
        {
            mat[path[i-1]][path[i]]=0;
            mat[path[i]][path[i-1]]=1;
        }
        fk=1;
        return;
    }
    state[idx]=1;
    for(i=0;i<=n*2+1;i++)
    {
        if(!mat[idx][i]||state[i])
            continue;
        path[C]=i;
        dfs(i,C+1);
        if(fk==1)
            return;
    }
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,T,cot,m;
	scanf("%d",&T);
	while(T--)
    {
        memset(mat,0,sizeof mat);
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        scanf("%d",&m);
        x.clear();y.clear();mx.clear();my.clear();
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
            x.emplace_back(a[i]);
            y.emplace_back(b[i]);
        }
        n=0;
        sort(x.begin(),x.end());
        auto it=unique(x.begin(),x.end());
        x.resize(distance(x.begin(),it));
        for(i=0;i<x.size();i++)
            mx[x[i]]=i+1;
        for(i=1;i<=m;i++)
            a[i]=mx[a[i]],n=max(n,a[i]);
        sort(y.begin(),y.end());
        it=unique(y.begin(),y.end());
        y.resize(distance(y.begin(),it));
        for(i=0;i<y.size();i++)
            my[y[i]]=i+1;
        for(i=1;i<=m;i++)
            b[i]=my[b[i]],n=max(n,b[i]);
        for(i=1;i<=n;i++)
        {
            mat[0][i]=1;
            mat[n+i][n*2+1]=1;
        }
        for(i=1;i<=m;i++)
        {
            mat[a[i]][n+b[i]]=1;
        }
        fk=1;
        while(fk==1)
        {
            fk=0;
            memset(state,0,sizeof state);
            dfs(0,1);
        }
        cot=0;
        for(i=n+1;i<=n*2;i++)
        {
            if(mat[n*2+1][i])
                cot++;
        }
        printf("%d\n",cot);
    }
}
