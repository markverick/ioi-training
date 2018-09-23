#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int maps[23][23];
int x[120],n,k;
int qs[120][120];
int jum[120][120][23];
vector<pair<int,int> > v[23];
int dp(int fst,int lst,int val)
{
    //printf("%d = %d %d\n",idx,fst,lst);
    if(jum[fst][lst][val]>=0)
        return jum[fst][lst][val];
    int i,j,l;
    int sum=0;
    if(fst==lst)
    {
        if(x[fst]==val)
            return 1;
        else
            return 0;
    }
    for(i=fst;i<=lst-1;i++)
    {
        //if(maps[qs[fst][i]][qs[i+1][lst]]==val)
        for(j=0;j<v[val].size();j++)
            sum+=dp(fst,i,v[val][j].X)*dp(i+1,lst,v[val][j].Y);
        sum%=2009;
    }
    return jum[fst][lst][val]=sum%2009;
}
int main()
{
    int i,j;
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
            scanf("%d",&maps[i][j]);
        }
    }
    memset(jum,-1,sizeof jum);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
            v[maps[i][j]].emplace_back(i,j);
        }
    }
    for(i=0;i<k;i++)
    {
        printf("%d\n",dp(0,n-1,i));
    }

}
