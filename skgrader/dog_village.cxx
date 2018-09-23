#include<bits/stdc++.h>
using namespace std;
int maps[1135][1135];
int n,m;
int dx[6]={1,-1,0,0};
int dy[6]={0,0,1,-1};
queue<tuple<int,int,int> >q;
int main()
{
    int i,j,k,x,y,time;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            scanf("%d",&maps[i][j]);
            if(maps[i][j]==0)
                q.emplace(0,i,j);
        }
    }
    while(!q.empty())
    {
        tie(time,x,y)=q.top();
        q.pop();
        for(i=0;i<4;i++)
        {
            if(time<)
        }
    }
}
