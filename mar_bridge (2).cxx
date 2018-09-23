#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
pair<int,int> p[100135];
int cross[100135],jum[100135];
int l,n,m;
int jump[100135];
int hi[100135];
int fin;
int dp(int idx)
{
    if(cross[idx]>=fin)
    {
        return 0;
    }
    printf("%d\n",idx);
    return dp(jump[idx])+1;
}
int main()
{
    int i,j,k;
    scanf("%d %d %d",&l,&n,&m);
    fin=l;
    memset(jum,-1,sizeof jum);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&p[i].X,&p[i].Y);
        if(p[i].Y==l)
            fin=min(fin,p[i].X);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&cross[i]);
    }
    sort(&cross[1],&cross[m+1]);
    sort(&p[1],&p[n+1]);
    for(i=1;i<=n;i++)
    {
        j=upper_bound(&cross[1],&cross[n+1],p[i].Y)-&cross[0]-1;
        if(cross[j]>=p[i].X)
        {
            hi[i]=j;
        }
    }
    j=1;
    for(i=1;i<=n;i++)
    {
        while(cross[j]<p[i].X)
        {
            jump[j]=max(jump[j],hi[i-1]);
            j++;
        }
        jump[j]=max(jump[j],hi[i]);
    }
    printf("%d",dp(1));
}
