#include<bits/stdc++.h>
using namespace std;
int jum[1000135];
int dp(int idx)
{
    if(jum[idx]>=0)
        return jum[idx];
    if(idx==0)
        return 1;
    return jum[idx]=(dp( floor((double)idx-sqrt(idx)) )+dp(floor(log(idx)) )+dp( floor(sin(idx)*sin(idx)*idx) ) )%1000000;
}
int main()
{
    int n;
    memset(jum,-1,sizeof jum);
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1)return 0;
        printf("%d\n",dp(n));
    }
}
