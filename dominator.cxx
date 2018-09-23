#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int mat[111][111],out[111][111],hsh[111];
int state[111],n,f=0;
int dfs(int idx,int ban,int targ)
{
    if(idx==ban)
        return 0;
    state[idx]=1;
    if(idx==targ)
    {
        f=1;
        return 1;
    }
    int mc=0,i;
    for(i=1;i<=n;i++)
    {
        if(state[i]||i==ban)
            continue;
        if(mat[idx][i])
            mc=max(mc,dfs(i,ban,targ));
    }
    return mc;
}
int dep(int idx)
{
    hsh[idx]=1;
    for(int i=1;i<=n;i++)
    {
        if(hsh[i]||i==idx)
            continue;
        if(mat[idx][i])
            dep(i);
    }
}
void dec(int n)
{
    printf("+");
    for(int i=1;i<n*2;i++)
        printf("-");
    printf("+\n");
}
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,T,t;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&mat[i][j]);
            }
        }
        memset(hsh,0,sizeof hsh);
        dep(1);
//        for(i=1;i<=n;i++)
//            printf("%d ",hsh[i]);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i==j)
                {
                    out[i][j]=1;
                    continue;
                }
                memset(state,0,sizeof state);
                k=dfs(1,i,j);
                if(k==1)
                    out[i][j]=0;
                else
                    out[i][j]=1;
            }
        }
        printf("Case %d:\n",t);
        dec(n);
        for(i=1;i<=n;i++)
        {
            printf("|");
            for(j=1;j<=n;j++)
            {
                if(out[i][j]==1&&hsh[j])
                    printf("Y|");
                else
                    printf("N|");
            }
            printf("\n");
            dec(n);
        }
    }
}
