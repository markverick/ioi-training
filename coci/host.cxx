#include<bits/stdc++.h>
#define M 1000000007
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long a[100135],b[100135],jum[100135][5],n;
///0 = use none 1 = use a, 2 = use first, 3 = use last b;
long long dp(long long idx,long long usage)
{
    if(jum[idx][usage]>=0)
        return jum[idx][usage];
    if(idx==n+1)
    {
        return 1;
    }
    long long sum=0;
    if(usage==0)
    {
        sum+=dp(idx+1,1)*a[idx];
        sum+=dp(idx+1,2)*b[idx];
    }
    else if(usage==1)
    {
        sum+=dp(idx+1,1)*a[idx];
        sum+=dp(idx+1,2)*b[idx];
        sum+=dp(idx+1,3)*b[idx-1];
    }
    else if(usage==2)
    {
        sum+=dp(idx+1,1)*a[idx];
        sum+=dp(idx+1,2)*b[idx];
        sum+=dp(idx+1,3)*(b[idx-1]-1);
    }
    else
    {
        sum+=dp(idx+1,1)*a[idx];
        sum+=dp(idx+1,2)*b[idx];
        sum+=dp(idx+1,3)*b[idx-1];
    }
    sum%=M;
    return jum[idx][usage]=sum;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k;
	memset(jum,-1,sizeof jum);
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(i=1;i<n;i++)
        scanf("%lld",&b[i]);
    printf("%lld",dp(1,0));
}
