#include<bits/stdc++.h>
using namespace std;
vector<double> d;
int main()
{
    int i,j,k,T=0;
    double a;
    while(scanf("%d %d",&n,&r)!=EOF)
    {
        T++;
        if(n==0&&r==0)
            return 0;
        for(i=1;i<=n;i++)
        {
            scanf("%f",&a);
            d.emplace_back(a);
        }
        sort(d.begin(),d.end());
        for(i=1;)

    }
}
