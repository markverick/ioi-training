#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char maps[1135][1135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,r,c,cot,mn=1000000000,x,y;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
    {
        scanf("%s",maps[i]+1);
    }
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(maps[i][j]!='X')
                continue;
            cot=0;
            for(k=i+1;k<=r;k++)
            {
                if(maps[k][j]=='^')
                    cot++;
                else
                    break;
            }
            for(k=i-1;k>=1;k--)
            {
                if(maps[k][j]=='v')
                    cot++;
                else
                    break;
            }
            for(k=j+1;k<=c;k++)
            {
                if(maps[i][k]=='<')
                    cot++;
                else
                    break;
            }
            for(k=j-1;k>=1;k--)
            {
                if(maps[i][k]=='>')
                    cot++;
                else
                    break;
            }
            if(cot<mn)
            {
                mn=cot;
                x=i;y=j;
            }
        }
    }
    printf("%d %d",x,y);
}
