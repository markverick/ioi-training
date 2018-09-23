#include<bits/stdc++.h>
using namespace std;
queue<tuple<int,int,int> > q;
unordered_map<int,unordered_map<int,bool> > hsh;
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

            if(hsh[a].find(b-1)==hsh[a].end())
            {
                hsh[a][b-1]=1;
                q.emplace(a,b-1,t+1);
            }
        }
        if(hsh[a].find(b+1)==hsh[a].end())
        {
            hsh[a][b+1]=1;
            q.emplace(a,b+1,t+1);
        }
        if(hsh[a+1].find(b)==hsh[a+1].end())
        {
            hsh[a+1][b]=1;
            q.emplace(a+1,b,t+1);
        }
        if(hsh[a-1].find(b)==hsh[a-1].end())
        {
            hsh[a-1][b]=1;
            q.emplace(a-1,b,t+1);
        }

    }
}
