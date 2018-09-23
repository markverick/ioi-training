#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back
using namespace std;
int n,L,m,a[111],result[1111];
int jum[111][111],Cot=-1,fu=0;
vector<int> vec;
void dp(int idx,int skill,int C)
{
    int i,j,sum=1;
    vector<pair<int,int> > v;
    for(i=idx+1;i<=n;i++)
    {
        v.emplace_back(a[i],-i);
    }
    sort(v.begin(),v.end());
    int tmp=0;
    if(Cot>=m)
    {
        for(i=1;i<C;i++)
        {
            printf("%d ",result[i]);
        }
        fu=1;
        return;
    }
    Cot++;
    for(i=0;i<v.size();i++)
    {
        if(v[i].X<=a[idx])
        {
            if(skill>0)
            {
                result[C]=v[i].X;
                dp(-v[i].Y,skill-1,C+1);
            }
        }
        else
        {
            result[C]=v[i].X;
            dp(-v[i].Y,skill,C+1);
        }
        if(fu)
            return;
    }
    return;
}
int main()
{
    int i,j,k;
    memset(jum,-1,sizeof jum);
    scanf("%d %d %d",&n,&L,&m);
    a[0]=-1;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    dp(0,L,1);
    if(fu==0)
        printf("-1");
}

