#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;
int a[550000];
int n,k;
int jum[550000];
int dp(int idx)
{
    if(jum[idx]>=0)
        return jum[idx];
    if(idx>=n-1)
    {
        return a[0];
    }
    int mn=999999999;
    int mini=999999999;
    int i;
    for(i=min(idx+k,n-1);i>=idx+1;i--)
    {
        if(a[i]>=mini)
            continue;
        mini=min(mini,a[i]);
        mn=min(mn,dp(i)+a[i]);

    }
    return jum[idx]=mn;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j;
    memset(jum,-1,sizeof jum);
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d\n",dp(0));
    for(i=0;i<n;i++)
        printf("%d\n",jum[i]);
}

