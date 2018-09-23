#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;
char in[320][5];
vector<pair<char,int> > adj[531];
set<char> st;
set<char> ::iterator it;
char result[320];
int n;
int hsh[320]; //edge hash
char jum[531][320];
char dfs(char vertex,int idx /*edge count*/)
{
    int i,j;
    if(jum[vertex][idx]>=0)
        return jum[vertex][idx];
    if(idx==n)
    {
        printf("%c ",*it);
        for(i=0;i<n;i++)
        {
            printf("%c ",result[i]);
        }
        exit(0);
        return 1;
    }
    char ch=0;
    for(i=0;i<adj[vertex].size();i++)
    {
        if(hsh[adj[vertex][i].Y]==1)
            continue;
        hsh[adj[vertex][i].Y]=1;
        result[idx]=adj[vertex][i].X;
        ch = max(ch, dfs(adj[vertex][i].X,idx+1) );
        hsh[adj[vertex][i].Y]=0;
    }
    return jum[vertex][idx]=ch;
}
int main()
{
    scanf("%d",&n);
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        scanf("%s",in[i]);
        adj[in[i][0]].push_back(MP(in[i][1],i));
        adj[in[i][1]].push_back(MP(in[i][0],i));
        st.insert(in[i][0]);
        st.insert(in[i][1]);
    }
    for(it=st.begin();it!=st.end();it++)
    {
        memset(jum,-1,sizeof jum);
        dfs(*it,0);
    }
}
