#include<bits/stdc++.h>
using namespace std;

char maps[22][22];
char result[2222];
int n;
int cot=0;
void dfs(int x,int y)
{
    if(x==n-1&&y==n-1)
    {
        int i;
        //printf("%s\n",result);
        for(i=0;i<n;i++)
        {
            if(result[i]!=result[2*n-i-2])
                return;
        }
        cot++;
        /*for(int i=0;i<2*n;i++)
            printf("%c",result[i]);
        printf("\n");*/
        //printf("%s\n",result);
        return;
    }
    //printf("%d\n",x+y);

    if(x+1<n&&y<=n)
    {
        result[x+y+1]=maps[x+1][y];
        dfs(x+1,y);
    }
    if(x<=n&&y+1<=n)
    {
        result[x+y+1]=maps[x][y+1];
        dfs(x,y+1);
    }
}
int main()
{
    freopen("palpath.in","r",stdin);
    freopen("palpath.out","w",stdout);
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",maps[i]);
    }
    result[0]=maps[0][0];
    dfs(0,0);
    printf("%d",n*n-cot);
}
