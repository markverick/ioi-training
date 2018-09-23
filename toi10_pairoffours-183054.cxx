#include<bits/stdc++.h>
using namespace std;
char s[1002];
int jum[1002][1002];
inline int dp(int fst,int lst)
{
    if(jum[fst][lst]>=0)
        return jum[fst][lst];
    if(fst+2>=lst)
    {
        if(fst>=lst)
            return 0;
        if(s[fst]==s[lst])
            return 1;
        return 0;
    }
    if(fst>=lst)
    {
        return 0;
    }
    int mc=0,i;
    if(s[fst]==s[lst])
    {
        return jum[fst][lst]=dp(fst+1,lst-1)+1;
    }
    else for(i=fst;i<lst;i++)
    {
        mc=max(mc,dp(fst,i)+dp(i+1,lst));
    }
    return jum[fst][lst]=mc;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    memset(jum,-1,sizeof jum);

    for(i=1;i<=n;i++)
    {
        scanf("%s",s+i);
    }
    for(i=1;i<n;i++)
    {
        if(s[i]==s[i+1])
            jum[i][i+1]=1;
        else
            jum[i][i+1]=0;
    }

    printf("%d\n",dp(1,n));
}
