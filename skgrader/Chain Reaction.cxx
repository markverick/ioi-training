#include<bits/stdc++.h>
#define MP make_pair
#define X first
#define Y second
using namespace std;
pair<int,int> p[100135];
int n;
int jum[100135];
int dp(int idx)
{
    if(jum[idx]>=0)
        return jum[idx];
    int i;
    if(idx==0)
    {
        return 0;
    }
    int mn=1000000000;
    i=lower_bound(&p[1],&p[n+1],make_pair(p[idx].Y,0))-&p[0]-1;
    mn=min(mn,dp(i)+idx-i-1);
    return jum[idx]=mn;
}
int main()
{
    int i,j,k,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        a+=1000000005;
        p[i]=make_pair(a,a-b);
    }
    sort(&p[1],&p[n+1]);
    p[n+1]=make_pair(p[n].X+1,p[n].Y+1);
    int mn=2000000010;
    memset(jum,-1,sizeof jum);
    for(i=n;i>=0;i--)
    {
        mn=min(mn,dp(i)+n-i);
    }
    printf("%d",mn);
}
