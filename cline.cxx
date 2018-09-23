#include<bits/stdc++.h>
using namespace std;
deque<int> deq;

int main()
{
    int i,j=1,k,T,t,d;
    char ch[3];
    char ch2[3];
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%s",ch);
        if(ch[0]=='A')
        {
            scanf("%s",ch2);
            if(ch2[0]=='R')
            {
                deq.emplace_back(j++);
            }
            else
            {
                deq.emplace_front(j++);
            }
        }
        else
        {
            scanf("%s %d",ch2,&d);
            if(ch2[0]=='R')
            {
                for(i=0;i<d;i++)
                {
                    deq.pop_back();
                }
            }
            else
            {
                for(i=0;i<d;i++)
                {
                    deq.pop_front();
                }
            }
        }
    }
    while(!deq.empty())
    {
        printf("%d\n",deq.front());
        deq.pop_front();
    }
}
