#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back
using namespace std;
char maps[60][60];
int adj[333][333],mat[333][333],dx[6]={1,-1,0,0},dy[6]={0,0,1,-1};
int car[60][60],park[60][60];
pair<int,int> p[135];
int jum[60][60],result[333],state[333],n,m,C=1,P=1,ck;
queue<pair<int,int> > q;
int chk(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=m&&maps[x][y]!='X'&&jum[x][y]==0)
        return 1;
    return 0;
}
void dfs(int idx,int cot)
{
    state[idx]=1;
    int i;
    if(idx==C+P+1)
    {
        for(i=1;i<cot;i++)
        {
            mat[result[i-1]][result[i]]=0;
            mat[result[i]][result[i-1]]=1;
        }
        ck=1;
        return;
    }
    for(i=0;i<=C+P+1;i++)
    {
        if(state[i]==0&&mat[idx][i]==1)
        {
            result[cot]=i;
            dfs(i,cot+1);
            if(ck==1)
                return;
        }
    }
}
int main()
{
    int i,j,k,x,y;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(car,0,sizeof car);
        memset(park,0,sizeof park);
        memset(p,0,sizeof p);
        C=1;P=1;
        for(i=1;i<=n;i++)
        {
            scanf("%s",maps[i]+1);
            for(j=1;j<=m;j++)
            {
                if(maps[i][j]=='P')
                    park[i][j]=P++;
                else if(maps[i][j]=='C')
                {
                    p[C]=MP(i,j);
                    car[i][j]=C++;
                }
            }
        }
        C--;P--;
        for(i=0;i<=C+P+1;i++)
            for(j=0;j<=C+P+1;j++)
                adj[i][j]=1000000000;
        for(i=1;i<=C;i++)
            adj[0][i]=0;
        for(i=1;i<=P;i++)
            adj[C+i][C+P+1]=0;
        for(i=1;i<=C;i++)
        {
            q.emplace(p[i]);
            memset(jum,0,sizeof jum);
            jum[p[i].X][p[i].Y]=1;
            while(!q.empty())
            {
                x=q.front().X;y=q.front().Y;
                q.pop();
                if(maps[x][y]=='P')
                {
                    adj[i][C+park[x][y]]=jum[x][y]-1;
                    //printf("%d -> %d = %d\n",i,park[x][y],jum[x][y]);
                }
                for(j=0;j<4;j++)
                {
                    if(chk(x+dx[j],y+dy[j])==0)
                        continue;
                    jum[x+dx[j]][y+dy[j]]=jum[x][y]+1;
                    q.emplace(x+dx[j],y+dy[j]);
                }
            }
        }
        int fst=0,lst=3000,mid,mn=1000000000;
        while(fst<=lst)
        {
            mid=(fst+lst)/2;
            //printf("%d <- %d -> %d\n",fst,mid,lst);
            for(i=0;i<=C+P+1;i++)
                for(j=0;j<=C+P+1;j++)
                    if(adj[i][j]<=mid)
                        mat[i][j]=1;
                    else
                        mat[i][j]=0;
            ck=1;
            result[0]=0;
            while(ck==1)
            {
                ck=0;
                memset(state,0,sizeof state);
                dfs(0,1);
            }
            int sum=0;
            for(i=C+1;i<=C+P;i++)
                sum+=mat[C+P+1][i];
            if(sum==C)
            {
                mn=min(mn,mid);
                lst=mid-1;
            }
            else
            {
                fst=mid+1;
            }
        }
        if(mn==1000000000)
            printf("-1\n");
        else
            printf("%d\n",mn);
    }
}
