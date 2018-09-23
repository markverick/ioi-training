#include<bits/stdc++.h>
using namespace std;
int n;
int a[15][5];
int full=0;
vector<int> ad[15];
vector<int> adj[15];
int dp(int idx,int bitmask,int pos)
{
    printf("%d\n",idx);
    if(bitmask==full)
    {
        //printf("F");
        return 0;
    }
    int mn=1000000000,i,j;
    for(i=0;i<adj[idx].size();i++)
    {
        //printf("%d %d\n",bitmask,bitmask|(1<<(adj[idx][i]-1)));
        if((bitmask|(1<<(adj[idx][i]-1)))==bitmask)
        {
            //printf("bitmask = %d\n",bitmask);
            //printf("%d\n",(bitmask|(1<<(adj[idx][i]-1)))==bitmask);
            //printf("E");
            continue;
        }
        for(j=max(1,pos-3);j<=min(n,pos+3);j++)
        {
            if(j==pos)
                continue;
            {
                mn=min(mn,dp(i,bitmask|(1<<(adj[idx][i]-1)),j)+abs(j-pos));
            }
        }
    }
    /*for(i=max(0,idx-3);i<=min(n,idx+3);i++)
    {
        if(i==idx)
            continue;
        i]if(bitmask&1<<(i-1)==0)
        {
            mn=min(mn,dp(i,bitmask|(1<<(i-1)),cot+1)+abs(i-idx));
        }
    }*/
    return mn;
}
int main()
{
    scanf("%d",&n);
    int i,j,k;
    full=1;
    for(i=0;i<n;i++)
    {
        full*=2;
    }
    full--;
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
        ad[i].push_back(a[i][1]);
        ad[a[i][1]].push_back(i);
        ad[i].push_back(a[i][2]);
        ad[a[i][2]].push_back(i);
        ad[i].push_back(a[i][3]);
        ad[a[i][3]].push_back(i);
    }
    for(i=1;i<=n;i++)
    {
        sort(ad[i].begin(),ad[i].end());
        if(!ad[i].empty());
            adj[i].push_back(ad[i][0]);
        for(j=1;j<ad[i].size();j++)
        {
            if(ad[i][j-1]!=ad[i][j])
            {
                adj[i].push_back(ad[i][j]);
            }
        }
    }
    /*for(i=1;i<=n;i++)
    {
        for(j=0;j<adj[i].size();j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }*/
    int mn=1000000000;
    //printf("%d\n",1<<4);
    for(i=1;i<=n;i++)
    {
        mn=min(mn,dp(i,1,1));
    }
    printf("%d\n",mn);
}
