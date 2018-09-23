#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1200000];
int chk[1200000];
set<int> st;
set<int> ::iterator it;
queue<int> q;
int main()
{
    int n;
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        st.insert(a);
        st.insert(b);
    }
    for(it=st.begin();it!=st.end();it++)
    {
        while(!q.empty())
            q.pop();
        memset(chk,0,sizeof 0);
        chk[*it]=1;
        q.push(*it);
        int fu=0;

        while(!q.empty())
        {
            int v=q.front();
            q.pop();
            for(i=0;i<adj[v].size();i++)
            {
                if(chk[adj[v][i]]==0)
                {
                    q.push(adj[v][i]);
                    chk[adj[v][i]]=chk[v]+1;
                }
                else if(chk[adj[v][i]]!=chk[v]+1)
                {
                    fu=1;
                    break;
                }
            }
            if(fu==1)
                break;
        }
        if(q.empty())
            fu=1;
        if(fu==0)
        {
            printf("Yes");
            exit(0);
        }
    }
    printf("No");

}
