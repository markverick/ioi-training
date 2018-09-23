#include<bits/stdc++.h>
using namespace std;
int n,m,cot=0;
void dfs(int x,int y)
{
    int i,j;
    if(x+1==y)
    {
        cot++;
        return;
    }
    int mc=0;
    for(i=x+1;i<y;i++)
    {
        dfs(x,i-1);
        dfs(i+1,y);
    }
    return;
}
int main()
{
    int i,j,k,T,fk;
    scanf("%d",&T);
    while(T--)
    {
        cot=0;
        fk=-1;
        scanf("%d %d",&n,&m);
        dfs(0,n+1);
        printf("%d\n",cot);
    }
}
