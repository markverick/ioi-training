#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> adj[222];
int state[222];
void dfs(int idx)
{
    state[idx]=1;
    for(int i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i]])
            continue;
        dfs(adj[idx][i]);
    }
}
char ch[3];
string s;
int main()
{
//	freopen("out.txt","w",stdout);
//	freopen("in.txt","r",stdin);
	int T,n,i,j,k,m,a,b,fk=0;
	cin >> T;
    cin >> s;
    m=s[0]-'A'+1;
	while(T--)
    {
        memset(state,0,sizeof state);
        n=m;
        for(i=0;i<n;i++)
            adj[i].clear();
        while(cin >> s)
        {
            if(s.size()==2)
            {
                adj[s[0]-'A'].emplace_back(s[1]-'A');
                adj[s[1]-'A'].emplace_back(s[0]-'A');
            }
            else
            {
                m=s[0]-'A'+1;
                break;
            }
        }
        int cot=0;
        memset(state,0,sizeof state);
        for(i=0;i<n;i++)
        {
            if(state[i])continue;
            cot++;
            dfs(i);
        }
        if(fk==0)
            printf("%d\n",cot);
        else
            printf("\n%d\n",cot);
        fk=1;
    }
}
