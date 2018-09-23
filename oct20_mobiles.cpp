#include<bits/stdc++.h>
using namespace std;
int n,m;
int ft[1135][1135];
void add(int x,int y,int val)
{
    int tmp=y;
    while(x<=n)
    {
        y=tmp;
        while(y<=n)
        {
            ft[x][y]+=val;
            y+=y&-y;
        }
        x+=x&-x;
    }
}
int sum(int x,int y)
{
    int sm=0,tmp=y;
    while(x>0)
    {
        y=tmp;
        while(y>0)
        {
            sm+=ft[x][y];
            y-=y&-y;
        }
        x-=x&-x;
    }
    return sm;
}
int main()
{
    int i,j,k,a,b,c,d,ch;
    scanf("%*d %d",&n);
    while(scanf("%d",&ch)!=EOF)
    {
        if(ch==1)
        {
            scanf("%d %d %d",&a,&b,&c);
            a++;b++;
            add(a,b,c);
        }
        else if(ch==2)
        {
            scanf("%d %d %d %d",&a,&b,&c,&d);
            a++;b++;c++;d++;
            printf("%d\n",sum(c,d)-sum(c,b-1)-sum(a-1,d)+sum(a-1,b-1));
        }
        else
            return 0;
    }
}
