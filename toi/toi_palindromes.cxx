#include<bits/stdc++.h>
using namespace std;
char str[2135];
int jum[2135],len;
int dp(int idx)
{
    if(jum[idx]>=0)
        return jum[idx];
    if(idx==len)
    {
        return 0;
    }
    int i,j,mn=1000000000,fu=0;
    for(i=idx;i<len;i++)
    {
        fu=0;
        for(j=idx;j<=(i+idx)/2;j++)
        {
            if(str[j]!=str[i-j+idx])
                fu=1;
        }
        if(fu==0)
        {
            mn=min(mn,dp(i+1)+1);
        }
    }
    return jum[idx]=mn;
}
int main()
{
    scanf("%s",str);
    memset(jum,-1,sizeof jum);
    len=strlen(str);
    printf("%d",dp(0)-1);
}
