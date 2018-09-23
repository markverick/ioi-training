#include<bits/stdc++.h>
#define MP(x,y,z) make_pair(x,make_pair(y,z))
#define PB(x) push_back(x)
using namespace std;
int n,m,timeLimit;
map<int,int> jum[12000];
vector<pair<int,pair<int,int > > > adj[120000];
//         tolevel   time,hod
int go(int idx,int time) //return minimum hodness
{
    //printf("IDX=%d\n",idx);
    if(jum[idx][time]!=0)
    {
        return jum[idx][time];
    }
    if(idx==n)
    {
        //printf("%d\n",time);
        if(time>timeLimit)
        {
            return 999999999;
        }
        else
        {
            //printf("Y");
            return 0;
        }
    }
    int lo=999999999;
    int i;
    for(i=0;i<adj[idx].size();i++)
    {
        lo=min(  lo,max(  go(adj[idx][i].first,time+adj[idx][i].second.first),adj[idx][i].second.second  )  );
    }
    return jum[idx][time] = lo;
}
int main()
{
    //adj[0].PB(MP(1,2,3));
    //printf("%d",adj[0][0].second.second);
    int i,j,k;
    int a,b,c,d;
    scanf("%d %d %d",&n,&m,&timeLimit);
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        adj[a].PB(MP(b,c,d));

    }
    printf("%d",go(1,0));
}
