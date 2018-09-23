#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
string s[135];
vector<int> adj[135];
set<int> st[135];
map<string,int> mp;
int hsh[135];
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,T=0;
	string a,b;
	while(cin >> n)
    {
        for(i=1;i<=n;i++)
        {
            s[i].clear();
            adj[i].clear();
            st[i].clear();
        }
        memset(hsh,0,sizeof hsh);
        mp.clear();
        T++;
        for(i=1;i<=n;i++)
        {
            cin >> s[i];
            mp[s[i]]=i;
        }
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
           cin >> a >> b;
           adj[mp[a]].emplace_back(mp[b]);
           st[mp[b]].insert(mp[a]);
        }
        cout << "Case #"<<T<<": Dilbert should drink beverages in this order:";
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(hsh[j]==0&&st[j].empty())
                {
                    for(k=0;k<adj[j].size();k++)
                    {
                        st[adj[j][k]].erase(j);
                    }
                    hsh[j]=1;
                    cout <<" "<<s[j];
                    break;
                }
            }
        }
        cout <<".\n\n";
    }
}
