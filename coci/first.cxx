#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char maps[22][22];
int main()
{
	int r,c,i,j,k;
	string mn={'z'+1},x;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
    {
        scanf("%s",maps[i]+1);
    }
	for(i=0;i<=r+1;i++)
        maps[i][0]='#',maps[i][c+1]='#';
    for(j=0;j<=c+1;j++)
        maps[0][j]='#',maps[r+1][j]='@';
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(maps[i][j]=='#')continue;
            if(maps[i-1][j]=='#')
            {
                x.clear();
                x.push_back(maps[i][j]);
                for(k=i+1;k<=r;k++)
                {
                    if(maps[k][j]=='#')break;
                    x.push_back(maps[k][j]);
                }
                if(x.size()>1)
                    mn=min(mn,x);
            }
            if(maps[i][j-1]=='#')
            {
                x.clear();
                x.push_back(maps[i][j]);
                for(k=j+1;k<=c;k++)
                {
                    if(maps[i][k]=='#')break;
                    x.push_back(maps[i][k]);
                }
                if(x.size()>1)
                    mn=min(mn,x);
            }

        }
    }
    cout << mn;
}
