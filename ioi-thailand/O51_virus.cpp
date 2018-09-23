#include<bits/stdc++.h>
int n,i,mc=0,a;
std::priority_queue<int> pq;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n*2;i++)
    {
        scanf("%d",&a);
        pq.emplace(-a);
    }
    while(pq.size()>n)
    {
        mc=std::max(mc,-pq.top());
        pq.pop();
    }
    printf("%d\n",mc);
}
