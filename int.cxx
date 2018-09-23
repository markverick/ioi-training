#include<bits/stdc++.h>
using namespace std;
int ft[10135],n;
void add(int x,int a)
{
    while(x<=n)
    {
        ft[x]+=a;
        x+=x&-x;
    }
}
int sum(int x)
{
    int sum=0;
    while(x>0)
    {
        sum+=ft[x];
        x-=x&-x;
    }
    return sum;
}
int main()
{
    int i,j,k,a,b,c;
    char ch[3];
    scanf("%d %d",&n,&k);
    for(i=1;i<=k;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='+')
        {
            scanf("%d %d %d",&a,&b,&c);
            add(b,a);
            add(c+1,-a);
        }
        else
        {
            scanf("%d %d %d",&a,&b,&c);
            add(b,-a);
            add(c+1,a);
        }
    }
    for(i=1;i<=n;i++)
    {
        printf("%d ",sum(i));
    }
}
