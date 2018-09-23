#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int fx[2000135],fy[2000135];
void addX(int x,int val)
{
    while(x<=2000010)
    {
        fx[x]+=val;
        x+=x&-x;
    }
}
int sumX(int x)
{
    int sm=0;
    while(x>0)
    {
        sm+=fx[x];
        x-=x&-x;
    }
    return sm;
}
void addY(int x,int val)
{
    while(x<=2000010)
    {
        fy[x]+=val;
        x+=x&-x;
    }
}
int sumY(int x)
{
    int sm=0;
    while(x>0)
    {
        sm+=fy[x];
        x-=x&-x;
    }
    return sm;
}
char s[300135];
int main()
{
//	freopen("out.txt","w",stdout);
//	freopen("in.txt","r",stdin);
	int i,j,k,n,m,a,b,x,y;
	long long sum=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        sum+=abs(a)+abs(b);
        addX(a+1000005,1);
        addY(b+1000005,1);
    }
//    printf("%d\n",sum);
    x=1000005;y=1000005;
    scanf("%s",s);
    for(i=0;i<m;i++)
    {
        if(s[i]=='S')//north
        {
            sum+=sumY(y);
            sum-=n-sumY(y);
            y++;
        }
        else if(s[i]=='J')//south
        {
            sum-=sumY(y-1);
            sum+=n-sumY(y-1);
            y--;
        }
        else if(s[i]=='I')//east
        {
            sum+=sumX(x);
            sum-=n-sumX(x);
            x++;
        }
        else //west
        {
            sum-=sumX(x-1);
            sum+=n-sumX(x-1);
            x--;
        }
        printf("%lld\n",sum);
    }
}
