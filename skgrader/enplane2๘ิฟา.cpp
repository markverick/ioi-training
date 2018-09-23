#include<bits/stdc++.h>
using namespace std;
int a,b,n;
vector<int> dat[1005];
// [plane][goToTown];
vector<int> haveTown[1005];

int p[1005];
int m[1005];
int jum[3][1005][10005];
int dp(int idx,int plane,int town)
{
   // printf("%d %d %d\n",idx,plane,town);
    if(jum[idx][plane][town]>=0)
        return jum[idx][plane][town];
    if(idx==1)
    {
        if(town==b)
        {
            //printf("F");
            return 0;
        }
        else
        {
            return 9999999;
        }
    }
    int mn=9999999;
    int i,j;
    for(i=0;i<dat[plane].size();i++)
    {
        if(town>dat[plane][i])
            continue;
        for(j=0;j<haveTown[ dat[plane][i] ].size();j++)
        {
            mn=min(mn,dp(idx+1,haveTown[dat[plane][i]][j],dat[plane][i])+p[dat[plane][i]]);
        }
    }
    //printf("=%d\n",mn);
    return jum[idx][plane][town]=mn;
}
int main()
{
    int i,j,k;
    int mn=9999999;
    scanf("%d %d %d",&a,&b,&n);
    memset(jum,-1,sizeof jum);
    for(i=1;i<=n;i++)
    {
        int c;
        scanf("%d %d",&p[i],&m[i]);
        for(j=1;j<=m[i];j++)
        {
            scanf("%d",&c);
            dat[i].push_back(c);
            haveTown[c].push_back(i);
        }
    }
    for(j=0;j<haveTown[a].size();j++)
    {
        mn=min(mn,dp(0,haveTown[a][j],a)+p[haveTown[a][j]]);
    }
    if(mn!=9999999)
        printf("%d",mn);
    else
        printf("-1");
}
