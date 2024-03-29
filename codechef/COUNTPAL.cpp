#include<bits/stdc++.h>
using namespace std;

char str[1200];
long long jum[1200];
char palin[1200][1200];
int len=0;
char isPalin(int fst,int lst)
{
    if(palin[fst][lst]!=-1)
        return palin[fst][lst];
    if(fst==lst)
        return 1;
    if(fst-1==lst)
        return 1;
    if(str[fst]==str[lst])
    {
        return palin[fst][lst]=isPalin(fst+1,lst-1);
    }
    else
        return palin[fst][lst]=0;
}
long long dp(int fst)
{
    if(jum[fst]>=0)
        return jum[fst];
    if(fst==len-1)
    {
        return 1;
    }
    if(fst==len)
        return 1;

    long long sum=0;
    int i,j,k;
    for(i=fst+1;i<=len;i++)
    {
        if(isPalin(fst,i-1))
        {
            sum+=dp(i);
            sum%=1000000007;
        }
    }
    //printf("%d\n",sum);
    return jum[fst]=sum%1000000007;
}

int main()
{
    int i,j,k;
    //freopen("out.txt","r",stdin);
    memset(jum,-1,sizeof jum);
    memset(palin,-1,sizeof palin);
    scanf("%s",str);
    len=strlen(str);

    printf("%lld\n",dp(0)%1000000007);
    /*for(i=0;i<len;i++)
    {
        printf("%d %d %lld\n",i,len-1,jum[i]);
    }*/
}
