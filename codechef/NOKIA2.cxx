#include<bits/stdc++.h>
using namespace std;
int n,m,cot=0;
int sum=0;
int hsh[1135];
void dfs(int x,int y)
{
    int i,j;
    if(x+1==y)
    {
        hsh[sum]=1;
//        cot++;
        return;
    }
    int mc=0;
    for(i=x+1;i<y;i++)
    {
        sum+=y-x;
        dfs(x,i-1);
        dfs(i+1,y);
        sum-=y-x;
    }
    return;
}
int main()
{
    int i,j,k,T,fk;
    scanf("%d",&T);
    while(T--)
    {
        memset(hsh,0,sizeof hsh);
        cot=0;
        fk=-1;
        scanf("%d %d",&n,&m);
        dfs(0,n+1);
        for(i=m;i>=0;i--)
        {
            if(hsh[i]==1)
            {
                fk=m-i;
                break;
            }
        }
        printf("%d\n",fk);
    }
}
