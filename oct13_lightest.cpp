#include<bits/stdc++.h>
using namespace std;

int n,m;
char ch[4];
priority_queue<pair<int,int> > pq;
int main()
{
    int i,j,k,w,u;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m+n;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='T')
        {
            scanf("%d %d",&w,&u);
            pq.emplace(-w,u);
        }
        else
        {
            if(!pq.empty())
            {
                printf("%d\n",pq.top().second);
                pq.pop();
            }
            else
            {
                printf("0\n");
            }
        }
    }
}
