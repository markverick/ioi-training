#include<bits/stdc++.h>
using namespace std;
int n,perm[300135],hsh[300135];
int dfs(int idx,int fst)
{
    if(idx>n)
        return 0;
    int sum=0;
    if(perm[idx]>fst)
    {
        hsh[perm[idx]]=1;
        sum=dfs(idx+1,fst)+1;
    }
    else if(perm[idx]==fst)
    {
        hsh[perm[idx]]=1;
        while(hsh[fst])
            fst++;
        sum=dfs(idx+1,fst);
        if(sum)
            sum++;
    }
    return sum;
}
int main()
{
	int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&j);
        perm[j]=i;
    }
    printf("%d",dfs(1,1));
}
