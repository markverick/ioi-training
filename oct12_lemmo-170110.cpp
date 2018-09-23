#include<bits/stdc++.h>
using namespace std;
int r,c;
char maps[135][135];
queue<tuple<int,int,int,int> >q;
int main()
{
    int i,j,k,x,y,d,cot=0,b;
    scanf("%d %d",&c,&r);
    for(i=1;i<=r;i++)
    {
        scanf("%s",maps[i]+1);
    }
    for(i=1;i<=c;i++)
    {
        q.emplace(1,i,-1,0);
        while(135)
        {
            tie(x,y,d,b)=q.front();
            q.pop();
            if(maps[x][y]=='.')
                q.emplace(x+1,y,d,b);
            else if(maps[x][y]=='#')
            {
                if(y+d>=1&&y+d<=c)
                    q.emplace(x,y+d,d,b);
                else
                    q.emplace(x,y,-d,b);
            }
            else if(maps[x][y]=='$')
            {
                cot++;
                break;
            }
            else
                break;
        }
        while(!q.empty())q.pop();
        q.emplace(1,i,1,0);
        while(135)
        {
            tie(x,y,d,b)=q.front();
            q.pop();
            if(maps[x][y]=='.')
                q.emplace(x+1,y,d,b);
            else if(maps[x][y]=='#')
            {
                if(y+d>=1&&y+d<=c)
                    q.emplace(x,y+d,d,b);
                else
                    q.emplace(x,y,-d,b);
            }
            else if(maps[x][y]=='$')
            {
                cot++;
                break;
            }
            else
                break;
        }
        while(!q.empty())q.pop();
    }
    printf("%d ",cot);
    for(i=1;i<=c;i++)
    {
        q.emplace(1,i,-1,0);
        while(135)
        {
            tie(x,y,d,b)=q.front();
            q.pop();
            if(maps[x][y]=='.')
                q.emplace(x+1,y,d,b);
            else if(maps[x][y]=='#')
            {
                if(y+d>=1&&y+d<=c)
                    q.emplace(x,y+d,d,b);
                else
                    q.emplace(x,y,-d,b);
                if(x<c&&b==0)
                {
                    q.emplace(x+1,y,d,1);
                }
            }
            else if(maps[x][y]=='$')
            {
                cot++;
                break;
            }
            else
                break;
        }
        while(!q.empty())q.pop();
        q.emplace(1,i,1,0);
        while(135)
        {
            tie(x,y,d,b)=q.front();
            q.pop();
            if(maps[x][y]=='.')
                q.emplace(x+1,y,d,b);
            else if(maps[x][y]=='#')
            {
                if(y+d>=1&&y+d<=c)
                    q.emplace(x,y+d,d,b);
                else
                    q.emplace(x,y,-d,b);
                if(x<c&&b==0)
                {
                    q.emplace(x+1,y,d,1);
                }
            }
            else if(maps[x][y]=='$')
            {
                cot++;
                break;
            }
            else
                break;
        }
        while(!q.empty())q.pop();
    }
    printf("%d",cot);
}
