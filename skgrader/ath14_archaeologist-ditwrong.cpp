#include<bits/stdc++.h>
using namespace std;
int d[333][333][3];
priority_queue<tuple<int,int,int,int> > pq;
int r,c,maps[333][333];
int main()
{
    int i,j,k,w,x,y,t;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            scanf("%d",&maps[i][j]);
            d[i][j][0]=-1000000000;
            d[i][j][1]=-1000000000;
        }
    }
    int mc=0;
    for(i=1;i<=c;i++)
    {
        d[1][i][0]=maps[1][i];
        pq.emplace(maps[1][i],1,i,0);
    }
    while(!pq.empty())
    {
        tie(w,x,y,t)=pq.top();
        pq.pop();
//        printf("%d %d %d",)
        if(t==0&&x==r)
        {
            pq.emplace(w,x,y,1);
            continue;
        }
        if(t==1&&x==1)
        {
            continue;
        }
        if(t==0)
        {
            for(i=-1;i<=1;i++)
            {
                if(y+i>=1&&y+i<=c)
                {
                    if(d[x+1][y+i][0]<w+maps[x+1][y+i])
                    {
                        d[x+1][y+i][0]=w+maps[x+1][y+i];
                        pq.emplace(w+maps[x+1][y+i],x+1,y+i,0);
                    }
                }
            }
        }
        else
        {
            for(i=-1;i<=1;i++)
            {
                if(y+i>=1&&y+i<=c)
                {
                    if(d[x-1][y+i][1]<w+maps[x-1][y+i])
                    {
                        d[x-1][y+i][1]=w+maps[x-1][y+i];
                        pq.emplace(w+maps[x-1][y+i],x-1,y+i,1);
                    }
                }
            }
        }
    }
    for(i=1;i<=c;i++)
    {
        mc=max(mc,d[1][i][1]);
    }
    printf("%d",mc);
}
