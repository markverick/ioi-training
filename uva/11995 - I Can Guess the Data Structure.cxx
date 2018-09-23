#include<bits/stdc++.h>
using namespace std;
stack<int> st;
queue<int> q;
priority_queue<int> pq;
vector<int> vs,vq,vpq,v;
int xs,xq,xpq;
int main()
{
//    freopen("out.txt","w",stdout);
    int i,j,k,n,a,b;
    while(scanf("%d",&n)!=EOF)
    {
        while(!st.empty())
            st.pop();
        while(!q.empty())
            q.pop();
        while(!pq.empty())
            pq.pop();
        vs.clear();
        vq.clear();
        vpq.clear();
        v.clear();
        xs=0;xq=0;xpq=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&a,&b);
            if(a==1)
            {
                st.emplace(b);q.emplace(b);pq.emplace(b);
            }
            else
            {
                v.emplace_back(b);
                if(!st.empty())
                {
                    vs.emplace_back(st.top());st.pop();
                    vq.emplace_back(q.front());q.pop();
                    vpq.emplace_back(pq.top());pq.pop();
                }
            }
        }
        for(i=0;i<v.size();i++)
        {
            if(vs[i]!=v[i])
                xs=1;
            if(vq[i]!=v[i])
                xq=1;
            if(vpq[i]!=v[i])
                xpq=1;
        }
        if(xs+xq+xpq<=1)
        {
            printf("not sure\n");
        }
        else if(xs+xq+xpq==3)
        {
            printf("impossible\n");
        }
        else if(xs==0)
            printf("stack\n");
        else if(xq==0)
            printf("queue\n");
        else
            printf("priority queue\n");
    }
}
