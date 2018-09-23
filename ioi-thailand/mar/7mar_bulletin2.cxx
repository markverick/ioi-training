#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back
using namespace std;
pair<int,pair<int,int> > v[300],h[300];
int mat[600][600],state[600],result[600],ck,V=1,H=1;
void dfs(int idx,int cot)
{
    state[idx]=1;
    int i;
    if(idx==V+H+1)
    {
        for(i=1;i<cot;i++)
        {
            mat[result[i-1]][result[i]]=0;
            mat[result[i]][result[i-1]]=1;
        }
        ck=1;
        return;
    }
    for(i=0;i<=V+H+1;i++)
    {
        if(state[i]==0&&mat[idx][i]==1)
        {
            result[cot]=i;
            dfs(i,cot+1);
            if(ck==1)return;
        }
    }
}
int main()
{
    int n,i,j,k,x1,y1,x2,y2;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if(x1==x2)
            if(y1<=y2)
                v[V++]=MP(x1,MP(y1,y2));
            else
                v[V++]=MP(x1,MP(y2,y1));
        if(y1==y2)
            if(x1<=x2)
                h[H++]=MP(y1,MP(x1,x2));
            else
                h[H++]=MP(y1,MP(x2,x1));
    }
    V--;H--;
    for(i=1;i<=V;i++)
        mat[0][i]=1;
    for(i=V+1;i<=V+H;i++)
        mat[i][V+H+1]=1;
    for(i=1;i<=V;i++)
    {
        for(j=1;j<=H;j++)
        {
            if(v[i].X>=h[j].Y.X&&v[i].X<=h[j].Y.Y&&h[j].X>=v[i].Y.X&&h[j].X<=v[i].Y.Y)
            {
                mat[i][V+j]=1;
            }
        }
    }
    ck=1;
    result[0]=0;
    while(ck==1)
    {
        ck=0;
        memset(state,0,sizeof state);
        dfs(0,1);
    }
    int sum=0;
    for(i=V+1;i<=V+H;i++)
    {
        sum+=mat[V+H+1][i];
    }
    printf("%d",V+H-sum);
}
