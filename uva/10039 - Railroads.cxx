#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
unordered_map<string,int> mp;
string name[111];
int n,m,p,x,y;
int ti[1111][111],town[1111][111];
vector<pair<int,int> > adj[111][1500];
pair<int,int> jum[111][1500];
pair<int,int> dp(int idx,int time)
{
    if(jum[idx][time].X>=0)
        return jum[idx][time];
    if(idx==y)
    {
        return make_pair(0,time);
    }
    int mn=1000000000,i,j,tmp,tmp2=0;
    for(i=time;i<=1440;i++)
    {
        for(j=0;j<adj[idx][i].size();j++)
        {
            tmp=dp(adj[idx][i][j].X,adj[idx][i][j].Y).Y;
            if(mn>tmp)
            {
                if(idx==x)
                    tmp2=i;
                mn=tmp;
            }
        }
    }
    return jum[idx][time]=make_pair(tmp2,mn);
}
int main()
{
//    freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,t,T,a,mn,st;
    pair<int,int> c;
    string b,aa,bb;
    cin >>T;
    for(t=1;t<=T;t++)
    {
        for(i=0;i<=100;i++)
        {
            for(j=0;j<1499;j++)
            {
                adj[i][j].clear();
                jum[i][j]=make_pair(-1,-1);
            }
        }
        cin >>n;
        for(i=1;i<=n;i++)
        {
            cin >>name[i];
            mp[name[i]]=i;
        }
        cin >>m;
        for(i=1;i<=m;i++)
        {
            cin >>p;
            for(j=1;j<=p;j++)
            {
                cin>>a>>b;
                ti[i][j]=60*(a/100)+a%100;
                town[i][j]=mp[b];
            }
            for(j=2;j<=p;j++)
            {
                adj[town[i][j-1]][ti[i][j-1]].emplace_back(town[i][j],ti[i][j]);
            }
        }
        cin >> a >> aa >> bb;
        a=60*(a/100)+a%100;
        x=mp[aa];y=mp[bb];
        mn=1000000000;
        st=0;
        for(i=1440;i>=a;i--)
        {
            c=dp(x,i);
            if(mn>c.Y)
            {
                st=c.X;
                mn=c.Y;
            }
        }
        printf("Scenario %d\n",t);
        if(mn!=1000000000)
        {
            printf("Departure %02d%02d ",st/60,st%60);
            for(i=0;i<aa.size();i++)
                printf("%c",aa[i]);
            printf("\n");
            printf("Arrival   %02d%02d ",mn/60,mn%60);
            for(i=0;i<bb.size();i++)
                printf("%c",bb[i]);
            printf("\n");
        }
        else
        {
            printf("No connection\n");
        }
        printf("\n");
    }
}
