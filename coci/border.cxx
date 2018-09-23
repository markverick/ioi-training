#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
#define EPS 0.00000001
using namespace std;
int a[111];
vector<int> v;
int main()
{
	int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            v.emplace_back(abs(a[i]-a[j]));
        }
    }
    int g=v[0];
    for(i=1;i<v.size();i++)
    {
        g=__gcd(g,v[i]);
    }
    double sq=sqrt(g);
    vector<int> out;
    for(i=2;i<sq-EPS;i++)
    {
        if(g%i==0)
        {
            out.emplace_back(i);
            out.emplace_back(g/i);
        }
    }
    k=nearbyint(sq);
    if(k*k==g)
        out.emplace_back(k);
    out.emplace_back(g);
    sort(out.begin(),out.end());
    for(i=0;i<out.size();i++)
    {
        printf("%d ",out[i]);
    }
}
