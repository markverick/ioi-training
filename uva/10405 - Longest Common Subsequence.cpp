#include<bits/stdc++.h>
using namespace std;
char s1[1200],s2[1200];
int jum[1200][1200];
int dp(int a,int b)
{
    if(a<0||b<0)
    {
        return 0;
    }

    else if(a<0)
    {
        a=0;
    }
    else if(b<0)
    {
        b=0;
    }
    if(jum[a][b]>=0)
    {
        return jum[a][b];
    }
    if(s1[a]==s2[b])
    {
        return jum[a][b] = 1+dp(a-1,b-1);
    }
    else
    {
        return jum[a][b] = max(dp(a-1,b),dp(a,b-1));
    }
}
int main()
{
    int l1,l2;
    while(gets(s1)&&gets(s2))
    {
        memset(jum,-1,sizeof jum);
        l1=strlen(s1);
        l2=strlen(s2);
        printf("%d\n",dp(l1-1,l2-1));
    }
}
