#include<bits/stdc++.h>
using namespace std;
int a[1135];
int jum[1135][1135];
priority_queue<tuple<int,int,int> > pq;
// -u time v
int main()
{
    int n,i,j,k,u,v,mag;
    scanf("%d",&n);
    for(i=0;i<=n+5;i++)
        for(j=0;j<=n+5;j++)
            jum[i][j]=1000000000;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    pq.emplace(0,0,1);
    while(!pq.empty())
    {
        tie(u,mag,v)=pq.top();
        u=-u;
        pq.pop();
        if(v==n)
        {
            printf("%d",u);
            return 0;
        }
        if(v+mag+1<=n&&jum[v+mag+1][mag+1]>u+a[v+mag+1])
        {
            pq.emplace(-u-a[v+mag+1],mag+1,v+mag+1);
            jum[v+mag+1][mag+1]=u+a[v+mag+1];
        }
        if(v-mag>=1&&jum[v-mag][mag]>u+a[v+mag])
        {
            pq.emplace(-u-a[v-mag],mag,v-mag);
            jum[v-mag][mag]=u+a[v+mag];
        }
    }
}
