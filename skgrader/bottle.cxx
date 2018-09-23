#include<bits/stdc++.h>
using namespace std;
int bot[100135];
int sorted[100135];
int iron[100135];
int main()
{
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&bot[i]);
    }
    for(i=1;i<=n;i++)
    {
        sorted[i]=max(bot[i],max(bot[i-1],bot[i+1]));
    }
    sort(&sorted[1],&sorted[n+1]);
    int idx=n,p;
    for(i=1;i<=m;i++)
    {
        scanf("%d",&iron[i]);
        p=upper_bound(&sorted[1],&sorted[idx+1],iron[i])-&sorted[1];
        printf("%d\n",idx-p);
        idx=p;

    }
}
