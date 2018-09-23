#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
char maps[30135][33];
vector<pair<int,int> > v[33];
int main()
{
	int i,j,k,r,c,n,a,x,y,anc;
	pair<int,int> p;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
        scanf("%s",maps[i]+1);
    for(i=1;i<=c;i++)
    {
        x=1;y=i;
        v[i].emplace_back(1,i);
        while(135)
        {
            if(maps[x+1][y]=='X')
                break;
            else if(maps[x+1][y]=='O')
            {
                if(maps[x][y-1]=='.'&&maps[x+1][y-1]=='.')
                    v[i].emplace_back(x,y-1),y--;
                else if(maps[x][y+1]=='.'&&maps[x+1][y+1]=='.')
                    v[i].emplace_back(x,y+1),y++;
                else
                    break;
            }
            else if(maps[x+1][y]=='.')
                v[i].emplace_back(x+1,y),x++;
            else
                break;
        }
    }
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        if(!v[a].empty())
        {
            p=v[a][v[a].size()-1];
            maps[p.X][p.Y]='O';
            for(i=1;i<=c;i++)
            {
                p=v[i][v[i].size()-1];
                if(maps[p.X][p.Y]=='.')
                    continue;
                v[i].pop_back();
                if(v[i].empty())
                    break;
                if(v[i].size()>=2)
                {
                    if(v[i][v[i].size()-1].X==v[i][v[i].size()-2].X)
                        v[i].pop_back();
                }
                p=v[i][v[i].size()-1];
                while(135)
                {
                    p=v[i][v[i].size()-1];
                    x=p.X;y=p.Y;
                    if(maps[x+1][y]=='X')
                        break;
                    else if(maps[x+1][y]=='O')
                    {
                        if(maps[x][y-1]=='.'&&maps[x+1][y-1]=='.')
                            v[i].emplace_back(x,y-1),y--;
                        else if(maps[x][y+1]=='.'&&maps[x+1][y+1]=='.')
                            v[i].emplace_back(x,y+1),y++;
                        else
                            break;
                    }
                    else if(maps[x+1][y]=='.')
                        v[i].emplace_back(x+1,y),x++;
                    else
                        break;

                }
            }
        }
    }
    for(i=1;i<=r;i++)
        printf("%s\n",maps[i]+1);
}
