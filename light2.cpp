#include<bits/stdc++.h>
#define MP make_pair
using namespace std;
priority_queue<pair<int,int> >q;
char ch[2];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int i,j,k;
    for(i=0;i<n+m;i++)
    {
        int a,b;
        scanf("%s",ch);
        if(ch[0]=='A')
        {
            scanf("%d %d",&a,&b);
            q.push(MP(-a,b));
        }
        else
        {
            if(q.empty())
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n",q.top().second);
                q.pop();
            }
        }

    }
}
