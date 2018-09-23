#include<bits/stdc++.h>
using namespace std;
stack<int> stk;
int main()
{
    int n;
    int i,j,k;
    scanf("%d",&n);
    int a,b;
    int cot=0;
    int mc=-1;
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        if(!stk.empty()&&b<stk.top())
        {
            while(!stk.empty()&&b<stk.top())
            {
                stk.pop();
            }
            stk.push(b);
        }
        else
        {
            stk.push(b);
        }
    }
    printf("%d",stk.size());
}
