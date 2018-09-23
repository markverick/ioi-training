#include<bits/stdc++.h>
using namespace std;
char maps[7][7];
queue<tuple<int,int,int,int,int,int,int,int,int,int > > q;
// idx,table,x,y,U,D,L,R,A,B
int table;
bool chk(int table,int x,int y)
{
    if( (table| (1<<((x-1)*4+(y-1) ) ) )==table )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int flip(int table,int x,int y)
{
    table^=(1<<((x-1)*4+(y-1) ) );
    return table;
}
int main()
{
    int T,i,j,sx,sy,idx,x,y,U,D,L,R,A,B,table,stable;
    scanf("%d",&T);
    while(T--)
    {
        for(i=1;i<=4;i++)
        {
            scanf("%s",maps[i]+1);
            for(j=1;j<=4;j++)
            {
                if(maps[i][j]=='D')
                {
                    sx=i;sy=j;
                    stable=( stable|(1<<4*(i-1)+j-1) );
                }
            }
            q.emplace(0,stable,sx,sy,0,0,0,0,0,0);
            while(!q.empty())
            {
                tie(idx,table,x,y,U,D,L,R,A,B)=q.front();q.pop();
                if(chk(table,x-1,y)==1 )
                {
                    if(U==0)
                    q.emplace(idx+1,flip(table,x-1,y),x-1,y, );
                }
            }
        }

    }
}
