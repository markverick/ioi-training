#include<bits/stdc++.h>
using namespace std;
int mc=0;
int jum[205][205][205];
void dfs(int x,int y,int w)
{
    if(x<=0||y<=0)
    {
        mc=max(mc,w);
        return;
    }
    if(jum[x][y][w]==1)
        return;
    jum[x][y][w]=1;
    dfs(x-2,y+1,w+1);
    dfs(x+1,y-2,w+1);
}
int main()
{
    int i,j,k,a,b;
    scanf("%d %d",&a,&b);
    dfs(a,b,0);
    printf("%d",mc);
}
