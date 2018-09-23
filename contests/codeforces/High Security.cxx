#include<bits/stdc++.h>
using namespace std;
char maps[5][1135];
int main()
{
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    int t,T,i,j,k,cot=0,n;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        cot=0;
        scanf("%d",&n);
        scanf("%s",maps[1]+1);
        scanf("%s",maps[2]+1);
        for(i=1;i<=n;i++)
        {
            if(maps[1][i]=='.')
            {
                if(maps[1][i-1]!='.'&&maps[1][i+1]!='.')
                {
                    maps[1][i]='G';
                    for(j=i;maps[2][j]=='.';j++)
                        maps[2][j]='G';
                    for(j=i-1;maps[2][j]=='.';j--)
                        maps[2][j]='G';
                    cot++;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            if(maps[2][i]=='.')
            {
                if(maps[2][i-1]!='.'&&maps[2][i+1]!='.')
                {
                    maps[2][i]='G';
                    for(j=i;maps[1][j]=='.';j++)
                        maps[1][j]='G';
                    for(j=i-1;maps[1][j]=='.';j--)
                        maps[1][j]='G';
                    cot++;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            if(maps[1][i]=='.'&&maps[1][i-1]!='.')
                cot++;
            if(maps[2][i]=='.'&&maps[2][i-1]!='.')
                cot++;
        }
        printf("Case #%d: %d\n",t,cot);
    }
}
