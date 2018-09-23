#include<bits/stdc++.h>
using namespace std;
int maps[531][531];
int d[531][531];
priority_queue<tuple<int,int,int> > pq;
int main()
{
    int T,i,j,k,x,y,w,mn=1000000000,r,c;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&r,&c);
        mn=1000000000;
        for(i=0;i<=r+1;i++)
            for(j=0;j<=c+1;j++)
                d[i][j]=1000000000;
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                scanf("%d",&maps[i][j]);
            }
        }
        for(i=1;i<=c;i++)
        {
            d[1][i]=0;
            pq.emplace(-maps[1][i],1,i);
        }
        while(!pq.empty())
        {
            tie(w,x,y)=pq.top();
            w=-w;
            pq.pop();
            if(x+1>r)
                continue;
            for(i=-1;i<=1;i++)
            {
                if(y+i>=1&&y+i<=c&&d[x+1][y+i]>w+maps[x+1][y+i])
                {
                    d[x+1][y+i]=w+maps[x+1][y+i];
                    pq.emplace(-w-maps[x+1][y+i],x+1,y+i);
                }
            }
        }
        for(i=1;i<=c;i++)
        {
            mn=min(mn,d[r][i]);
        }
        printf("%d\n",mn);
    }
}
