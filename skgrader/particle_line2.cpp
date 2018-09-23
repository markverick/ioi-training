#include<bits/stdc++.h>
using namespace std;
stack<pair<int,int> >stk;
int main()
{
    int n;
    int i,j,k,t;
    scanf("%d %d",&n,&t);
    int a,b;
    int cot=0;
    int mc=-1;
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        if(!stk.empty()&&b<stk.top().second)
        {
            while(!stk.empty()&&b<stk.top().second&&(a-stk.top().first)/(stk.top().second-b)<=t)
            {
                stk.pop();
            }
            stk.push(make_pair(a,b));
        }
        else
        {
            stk.push(make_pair(a,b));
        }
    }
    printf("%d",stk.size());
}
