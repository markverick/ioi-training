#include<bits/stdc++.h>
#define MP(x,y) make_pair(x,y)
using namespace std;
int dat[10000];
int n;
pair<int,int> jum[250][10000];
int x2(int n)
{
    return n*n;
}
pair<int,int> dp(int level,int idx)
{
    if(jum[level][idx].first>=0)
        return jum[level][idx];
    if(level==n)
    {
        return MP(x2(dat[0]),dat[0]);
    }
    return jum[level][idx] = MP( max(dp(level+1,idx+level).first+x2(dat[idx+level]),dp(level+1,idx+level+1).first+x2(dat[idx+level+1]))
              ,
              max(dp(level+1,idx+level).second+dat[idx+level],dp(level+1,idx+level+1).second+dat[idx+level+1])
              );
}
int main()
{
    memset(jum,-1,sizeof jum);
    //printf("=%d %d =\n",jum[2][7].first,jum[3][7].second);
    int i,j,k;
    int idx=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            scanf("%d",&dat[idx++]);
        }
    }
    pair<int,int> out = dp(1,0);
    printf("%d %d %c%c",out.first,out.second,out.first%26+'a',out.second%26+'a');
}
