#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
queue<pair<int,int> > q;
int ban[15];
int main()
{
    int n,i,a,b,c;
    scanf("%d",&n);
    q.emplace(n,0);
    while(!q.empty())
    {
        a=q.front().X;c=q.front().Y;
        q.pop();
        b=a;
        if(a==1)
        {
            printf("%d",c);
            return 0;
        }
        memset(ban,0,sizeof ban);
        while(b>0)
        {
            ban[b%10]=1;
            b/=10;
        }
        for(i=2;i<=5;i++)
        {
            if(a%i==0)
                ban[i]=1;
        }
        for(i=2;i<=5;i++)
        if(ban[i]==0)
        {
            q.emplace(a-i,c+1);
        }
    }
    printf("-1");
}
