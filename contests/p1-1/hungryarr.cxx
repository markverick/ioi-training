#include<bits/stdc++.h>
using namespace std;
queue<tuple<int,int,int> > q;
map<pair<int,int>,int > hsh;
int main()
{
    int n,k,a,b,t;
    scanf("%d %d",&n,&k);
    q.emplace(n,k,1);
    while(!q.empty())
    {
        tie(a,b,t)=q.front();
        q.pop();
        if(a%b==0)
        {
            printf("%d",t-1);
            return 0;;
        }
        if(b>=2)
        {
            if(hsh.find(make_pair(a,b-1))==hsh.end())
            {
                hsh[make_pair(a,b-1)]=t;
                q.emplace(a,b-1,t+1);
            }
        }
        if(hsh.find(make_pair(a,b+1))==hsh.end())
        {
            hsh[make_pair(a,b+1)]=t;
            q.emplace(a,b+1,t+1);
        }
        if(hsh.find(make_pair(a+1,b))==hsh.end())
        {
            hsh[make_pair(a+1,b)]=t;
            q.emplace(a+1,b,t+1);
        }
        if(hsh.find(make_pair(a-1,b))==hsh.end())
        {
            hsh[make_pair(a-1,b)]=t;
            q.emplace(a-1,b,t+1);
        }
        if(hsh.find(make_pair(a-1,b))==hsh.end())
        {
            hsh[make_pair(a-1,b)]=t;
            q.emplace(a-1,b,t+1);
        }

    }
}
