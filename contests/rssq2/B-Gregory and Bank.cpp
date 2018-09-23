#include<bits/stdc++.h>
using namespace std;
char s[333];
int a[135],b[135];
int main()
{
    int i,j,k,T,n,m,sum=0,len;
    stack<int> x,y;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d",&b[i]);
        }
        sort(&a[1],&a[n+1]);
        sort(&b[1],&b[m+1]);
        while(!x.empty())x.pop();
        while(!y.empty())y.pop();
        for(i=1;i<=n;i++)
        {
            x.emplace(a[i]);
        }
        for(j=m;j>=1;j--)
        {
            y.emplace(b[j]);
        }
        scanf("%s",s);
        len=strlen(s);
        sum=0;
        if(s[0]=='-')
        {
            printf("%d\n",m);
            continue;
        }
        for(i=0;i<len;i++)
        {
            if(s[i]=='+')
            {
                if(!x.empty())
                {
                    sum+=x.top();
                    x.pop();
                }
            }
            else
            {
                if(!y.empty())
                {
                    if(sum>=y.top())
                    {
                        sum-=y.top();
                        y.pop();
                    }
                    else
                    {
                        k=y.top();
                        y.pop();
                        y.emplace(k-sum);
                    }
                }
            }
        }
        printf("%d\n",y.size());
    }
}
