#include<bits/stdc++.h>
using namespace std;
char maps[70][70];

int main()
{
    //freopen("moocrypt.in","r",stdin);
    //freopen("moocrypt.out","w",stdout);
    int i,j;
    int r,c;
    scanf("%d %d",&r,&c);
    for(i=2;i<=r+1;i++)
    {
        scanf("%s",maps[i]+2);
    }
    int mc=0;
    for(char k='A';k<='Z';k++)
    {
        if(k=='M')
            continue;
        for(char m='A';m<='Z';m+=1)
        {
            if(m=='O')
                continue;
            int cot=0;
            if(k==m)
                continue;
            for(i=2;i<=r+1;i++)
            {
                for(j=2;j<=c+1;j++)
                {
                    if(maps[i][j]==k)
                    {
                        if(maps[i+1][j]==m&&maps[i+2][j]==m)
                            cot++;
                        if(maps[i-1][j]==m&&maps[i-2][j]==m)
                            cot++;
                        if(maps[i][j+1]==m&&maps[i][j+2]==m)
                            cot++;
                        if(maps[i][j-1]==m&&maps[i][j-2]==m)
                            cot++;
                        if(maps[i+1][j+1]==m&&maps[i+2][j+2]==m)
                            cot++;
                        if(maps[i-1][j-1]==m&&maps[i-2][j-2]==m)
                            cot++;
                        if(maps[i+1][j-1]==m&&maps[i+2][j-2]==m)
                            cot++;
                        if(maps[i-1][j+1]==m&&maps[i-2][j+2]==m)
                            cot++;
                    }
                }
            }
            mc=max(mc,cot);
        }
    }
    printf("%d",mc);
}
