#include<bits/stdc++.h>
#define MP make_pair
#define X first
#define Y second
using namespace std;
int hsh[1000135];
map<pair<int,int>,int> mp;
int main()
{
    int i,j,k,n,m,a,b;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(hsh,0,sizeof hsh);
        mp.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            hsh[a]++;
            mp[MP(a,hsh[a])]=i;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            if(mp.find(MP(b,a))!=mp.end())
            {
                printf("%d\n",mp[MP(b,a)]);
            }
            else
            {
                printf("0\n");
            }
        }
    }
}
