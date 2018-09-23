#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,i,j,k,t,n;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        int mn=1000000000;
        for(i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                mn=min(mn,abs(i-(n/i)));
            }
        }
        printf("Case #%d\n%d\n",t,mn);
    }
}

