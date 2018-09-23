#include<bits/stdc++.h>
using namespace std;
int hsh[1000135],hs[1000135];
vector<int> p;
int main()
{
    int T,n,i,j,k,a,prod;
    for(i=2;i<=1000000;i++)
    {
        if(hsh[i]==0)
        {
            p.emplace_back(i);
            for(j=i;j<=1000000;j+=i)
                hsh[j]=1;
        }
    }
    scanf("%d",&T);
    while(T--)
    {
        memset(hs,0,sizeof hs);
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            for(j=0;j<p.size();j++)
            {
                if(a<2)
                    break;
                while(a%p[j]==0)
                {
                    hs[j]++;
                    a/=p[j];
                }
            }
        }
        prod=1;
        for(i=0;i<p.size();i++)
        {
            prod*=hs[i]+1;
        }
        printf("%d\n",prod);
    }
}
