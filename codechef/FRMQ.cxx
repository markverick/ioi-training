#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long a[100135],sp[100135][50],lg[100135];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long i,j,k,T,n,x,y,m;
    lg[1]=0;
    for(i=2;i<100005;++i)
    {
        lg[i]=lg[i/2]+1;
    }
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        sp[i][0]=a[i];
    }
    for(i=1;(1<<i)<=n;i++)
    {
        for(j=1;j+(1<<i)-1<=n;j++)
        {
            sp[j][i]=max(sp[j][i-1],sp[j+(1<<(i-1))][i-1]);
        }
    }
    cin >> m>>x>>y;
    long long sum=0,p,q;
    while(m--)
    {
        if(x>y)
            p=y+1,q=x+1;
        else
            p=x+1,q=y+1;
        k=lg[q-p+1];
        sum+=max(sp[p][k],sp[q-(1<<k)+1][k]);
        x=(x+7)%(n-1);
        y=(y+11)%(n);
    }
    cout << sum;
}
