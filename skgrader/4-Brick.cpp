#include<bits/stdc++.h>
#define mp make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,t,cas,m;
    double d;
    scanf("%d",&t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        m=ceil((double)n/2);
        d=m*(m-1);
        d/=2;
        printf("Case #%d\n%.0lf\n",cas,ceil(d));
    }
}
