#include<bits/stdc++.h>
using namespace std;
int psh(int idx,int n);
int dp(int idx)
{
    //printf("WIDTH %d : \n",idx);
    if(idx==1)
        return 1;
    return (psh(1,idx-1)+1)%10001;
}
int psh(int idx,int n)
{
    if(idx==n+1)
    {
        return 0;
    }
    int i,sum=0;
    for(i=idx;i<=n;i++)
    {
        sum+=psh(i+1,n)+dp(i-idx+1);
        sum%=10001;
    }
    return sum;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",dp(n));
}
