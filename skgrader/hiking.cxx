#include<bits/stdc++.h>
#define MT make_tuple
using namespace std;
priority_queue<tuple<int,int,int> > pq;
/// w idx
char maps[135][135];
int dx[10]={1,1,1,0,0,-1,-1,-1};
int dy[10]={-1,0,1,-1,1,-1,0,1};
int main()
{
    int T,i,j,k,r,c,sx,sy,x,y,energy,idx;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&r,&c);
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                scanf("%s",maps[i]+1);
            }
        }
        scanf("%d %d",&sx,&sy);
        sx++;sy++;
        char v,u;
        pq.emplace(0,sx,sy);
        while(!pq.empty())
        {
            tie(energy,x,y)=pq.top();
            pq.pop();
            u=maps[x][y];
            for(i=0;i<8;i++)
            {
                v=maps[x+dx[i]][y+dy[i]];
                if(v=='#')
                    continue;
                if()
                pq.emplace(energy+ abs((v-'0')-(u-'0'))*abs((v-'0')-(u-'0')) )
            }
        }
    }
}
