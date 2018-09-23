#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],hsh[10005],ha[10005];
int mn=1000000000,n,m;
inline void dfs(int idx,int cot)
{
    int i;
    if(idx>m)
    {
        mn=cot;
        for(i=1;i<=n;i++)
            ha[i]=hsh[i];
        return;
    }
    if(hsh[a[idx]]==0&&hsh[b[idx]]==0)
    {
        if(cot+1>=mn||cot+1>20)
            return;
        hsh[a[idx]]=1;
        dfs(idx+1,cot+1);
        hsh[a[idx]]=0;
        hsh[b[idx]]=1;
        dfs(idx+1,cot+1);
        hsh[b[idx]]=0;
    }
    else
    {
        dfs(idx+1,cot);
    }
}
int main()
{
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
    }
    dfs(1,0);
    printf("%d\n",mn);
    for(i=1;i<=n;i++)
    {
        if(ha[i])
            printf("%d\n",i);
    }
}
