#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int m;
struct numm
{
public:
    int a,b,c;
    bool operator <(const numm &x)
    {
        int k=a*x.a,i,j;
        i=m*1000*x.a+b*k;
        j=m*1000*a+x.b*k;
        if(i==j)
            return b>x.b;
        return i<j;
    }
};
numm F[33];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&F[i].a,&F[i].b);
            F[i].c=i;
        }
        sort(&F[1],&F[n+1]);
        for(i=1;i<=n;i++)
        {
            printf("%d\n",F[i].c);
        }
    }
}
