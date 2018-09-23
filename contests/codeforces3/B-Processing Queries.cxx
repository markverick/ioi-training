#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,i,j,k,n,m,sz=0,idx=0;
    queue<long long> q;
    scanf("%I64d %I64d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&a,&b);
        while(!q.empty()&&q.front()<=a) ///
        {
            q.pop();
        }
        if(a<idx)
        {
            if(q.size()<m+1)
            {
                idx+=b;
                q.emplace(idx);
                printf("%I64d ",idx);
            }
            else
            {
                printf("-1 ");
            }
        }
        else
        {
            idx=a+b;
            q.emplace(idx);
            printf("%I64d ",idx);
        }
    }
}
