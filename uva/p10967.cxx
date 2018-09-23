#include<bits/stdc++.h>
using namespace std;
char maps[135][135];
int d[135][135],r,c,C,cost[135][135],idx[13500],idy[13500];
int dx[6]={-1,1,0,0};
int dy[6]={0,0,1,-1};
///        N S E W
priority_queue<tuple<int,int,int> > pq;
int chk(int x,int y,int dir)
{
    if(x>=0&&x<=r&&y>=0&&y<=c)
    {
        if(maps[x][y]=='.')
            return 1;
        else if(maps[x][y]=='N'&&dir==1)
            return 2;
        else if(maps[x][y]=='S'&&dir==0)
            return 2;
        else if(maps[x][y]=='E'&&dir==3)
            return 2;
        else if(maps[x][y]=='W'&&dir==2)
            return 2;
    }
    return 0;
}
int findcost(int x,int y,int dir)
{
    if(maps[x][y]=='N')
        switch(dir)
        {
            case 0: return 1;
            case 1: return cost[x][y]*2+1;
            case 2: case 3:return cost[x][y]+1;
        }
    else if(maps[x][y]=='S')
        switch(dir)
        {
            case 0: return cost[x][y]*2+1;
            case 1: return 1;
            case 2: case 3:return cost[x][y]+1;
        }
    else if(maps[x][y]=='E')
        switch(dir)
        {
            case 2: return 1;
            case 3: return cost[x][y]*2+1;
            case 0: case 1:return cost[x][y]+1;
        }
    else if(maps[x][y]=='W')
        switch(dir)
        {
            case 3: return 1;
            case 2: return cost[x][y]*2+1;
            case 0: case 1:return cost[x][y]+1;
        }
    else
    {
        return 1;
    }
}
int main()
{
    int T,i,j,k,w,x,y,ch,cst;
    scanf("%d",&T);
    while(T--)
    {
        k=1;
        for(i=0;i<=105;i++)
            for(j=0;j<=105;j++)
                d[i][j]=1000000000;
        scanf("%d %d",&r,&c);
        for(i=1;i<=r;i++)
        {
            scanf("%s",maps[i]+1);
            for(j=1;j<=c;j++)
            {
                if(maps[i][j]>='A'&&maps[i][j]<='Z')
                {
                    idx[k]=i;
                    idy[k++]=j;
                }
            }
        }
//        scanf("%d",&C);
        k--;
        for(i=1;i<=k;i++)
        {
            scanf("%d",&cost[idx[i]][idy[i]]);
        }
        d[r][1]=0;
        pq.emplace(0,r,1);
        while(!pq.empty())
        {
            tie(w,x,y)=pq.top();
            w=-w;
//            printf("%d\n",w);
            pq.pop();
            for(i=0;i<4;i++)
            {
                ch=chk(x+dx[i],y+dy[i],i);
                if(ch==0)
                    continue;
                cst=findcost(x,y,i);
                //printf("CST = %d\n",cst);
                if(d[x+dx[i]][y+dy[i]]>w+cst)
                {
                    d[x+dx[i]][y+dy[i]]=w+cst;
                    pq.emplace(-w-cst,x+dx[i],y+dy[i]);
                }
            }
        }
        if(d[1][c]==1000000000)
        {
            printf("Poor Kianoosh\n");
        }
        else
        {
            printf("%d\n",d[1][c]);
        }
    }
}
