#include<bits/stdc++.h>
using namespace std;
long long d[1135][1135];
priority_queue<tuple<long long,long long,long long> > pq;
int main()
{
    long long n,i,j,k,a,b,x,y,w;
    scanf("%I64d %I64d",&a,&b);
    pq.emplace(0,a,b);
    while(!pq.empty())
    {
        tie(w,a,b)=pq.top();
        pq.pop();
        if(a==0||b==0)
        {
            continue;
        }
        x=a-2;y=b+1;
        if(x>=0)
        {
            if(w+1>d[x][y])
            {
                d[x][y]=w+1;
                pq.emplace(w+1,x,y);
            }
        }
        x=a+1;y=b-2;
        if(y>=0)
        {
            if(w+1>d[x][y])
            {
                d[x][y]=w+1;
                pq.emplace(w+1,x,y);
            }
        }
    }
    long long mc=0;
    for(i=0;i<=1005;i++)
        mc=max(mc,d[0][i]),mc=max(mc,d[i][0]);
    printf("%I64d\n",mc);
}
