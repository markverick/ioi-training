#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[135][12];
int state[30],hsh[30];
vector<int> adj[30];
void dfs(int idx,int fst,int lst)
{
    while(s[fst][idx]==0)
        fst++;
    if(fst>=lst)
        return;
    int i,j=fst;
    for(i=fst+1;i<=lst;i++)
    {
        if(s[i][idx]!=s[i-1][idx])
        {
            adj[s[i-1][idx]-'a'].emplace_back(s[i][idx]-'a');
            dfs(idx+1,j,i-1);
            j=i;
        }
    }
    dfs(idx+1,j,lst);
}
int dag(int idx)
{
    state[idx]=1;
    int mc=0;
    for(int i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i]]==1)
            return 1;
        else if(state[adj[idx][i]]==2)continue;
        mc=max(mc,dag(adj[idx][i]));
    }
    state[idx]=2;
    return mc;
}
int jum[30];
int dp(int idx)
{
    if(jum[idx]>=0)
        return jum[idx];
    int i,mc=0;
    for(i=0;i<adj[idx].size();i++)
    {
        mc=max(mc,dp(adj[idx][i]));
    }
    return jum[idx]=mc+1;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,ch=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
        for(j=1;s[i][j];j++)
        {
            if(hsh[s[i][j]-'a']==0)
            {
                ch++;
                hsh[s[i][j]-'a']=1;
            }
        }
    }
    dfs(1,1,n);
//    for(i=0;i<26;i++)
//    {
//        if(adj[i].empty())continue;
//        printf(" - %c: \n",i+'a');
//        for(j=0;j<adj[i].size();j++)
//            printf("%c ",adj[i][j]+'a');
//        printf("\n");
//    }
    int fk=0;
    for(i=0;i<26;i++)
    {
        if(hsh[i]==0)continue;
        memset(state,0,sizeof state);
        fk=max(fk,dag(i));
    }
    if(fk)
    {
        printf("!");
        return 0;
    }
    int mc=0;
    for(i=0;i<26;i++)
    {
        if(hsh[i]==0)continue;
        memset(jum,-1,sizeof jum);
        if(dp(i)==ch)
        {
            for(i=ch;i>=1;i--)
            {
                for(j=0;j<26;j++)
                {
                    if(jum[j]==i)
                        printf("%c",j+'a');
                }
            }
            return 0;
        }
    }
    printf("?");
}
