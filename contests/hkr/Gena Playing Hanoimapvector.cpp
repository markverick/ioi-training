#include<bits/stdc++.h>
using namespace std;
vector<int> st,ed;
queue<vector<int> > q;
map<vector<int>,int> mv;
int hsh[6];
int main()
{
    int i,j,k,n,a,tmp;
    vector<int> x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        st.emplace_back(a);
        ed.emplace_back(1);
    }
    q.emplace(st);
    mv[st]=1;
    while(!q.empty())
    {
        x=q.front();
        y=x;
        q.pop();
        memset(hsh,0,sizeof hsh);
        for(i=0;i<x.size();i++)
        {
            for(j=1;j<=4;j++)
            {
                if(hsh[j]==0&&x[i]!=j)
                {
                    y[i]=j;
                    if(mv[y]==0)
                    {
                        mv[y]=mv[x]+1;
                        q.emplace(y);
                    }
                    y[i]=x[i];
                }
            }
            hsh[x[i]]=1;
        }
    }
    printf("%d",mv[ed]-1);
}
