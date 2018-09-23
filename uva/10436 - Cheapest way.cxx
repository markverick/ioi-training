#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
string name[22];
int cost[22],d[22],e[22],p[22];
vector<pair<int,int> > adj[22];
priority_queue<pair<int,int> > pq;
unordered_map<string,int> mp;
int main()
{
//    freopen("out.txt","w",stdout);
    int T,t,i,j,k,n,m,c,Q,q,x,y,u,w,num;
    stack<int> st;
    string a,b;
    cin >> T;
    for(t=1;t<=T;t++)
    {
        if(t>1)
            printf("\n");
        cin >> n;
        mp.clear();
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
        }
        for(i=1;i<=n;i++)
        {
            cin >> name[i] >> cost[i];
            mp[name[i]]=i;
        }
        cin >> m;
        for(i=1;i<=m;i++)
        {
            cin >> a >> b >> c;
            adj[mp[a]].emplace_back(mp[b],c*2+cost[mp[b]]);
            adj[mp[b]].emplace_back(mp[a],c*2+cost[mp[a]]);
        }
        cin >> Q;
        printf("Map #%d\n",t);
        for(q=1;q<=Q;q++)
        {
            memset(p,0,sizeof p);
            printf("Query #%d\n",q);
            for(i=1;i<=n;i++)
            {
                d[i]=1000000000;
            }
            cin >> a >> b >> num;
            x=mp[a];y=mp[b];
            d[x]=cost[x];
            pq.emplace(-cost[x],x);
            while(!pq.empty())
            {
                tie(w,u)=pq.top();
                pq.pop();
                w=-w;
                for(i=0;i<adj[u].size();i++)
                {
                    if(w+adj[u][i].Y<d[adj[u][i].X])
                    {
                        p[adj[u][i].X]=u;
                        d[adj[u][i].X]=w+adj[u][i].Y;
                        pq.emplace(-w-adj[u][i].Y,adj[u][i].X);
                    }
                }
            }
            c=y;
            while(c>0)
            {
                st.emplace(c);
                c=p[c];
            }
            while(!st.empty())
            {
                for(i=0;i<name[st.top()].size();i++)
                {
                    printf("%c",name[st.top()][i]);
                }

                st.pop();
                if(!st.empty())printf(" ");
            }
            printf("\nEach passenger has to pay : %.2f taka\n",(double)(d[y])*1.1/num);
        }
    }
}
