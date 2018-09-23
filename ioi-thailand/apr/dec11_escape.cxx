#include<bits/stdc++.h>
using namespace std;
unsigned int n,mclen=0;
unsigned int a[30][15];
char str[30][15];
unsigned int len[30];
unsigned int jum[1350000];
inline unsigned int dp(unsigned int bit,unsigned int idx,unsigned int sum)
{
    if(jum[bit]>0)
        return jum[bit];
    if(idx>=n+1)
        return 0;
    unsigned int fu=0,tot=0,b4=sum,tmp;
    unsigned int mc=0,i,j;
    //prunsigned intf("%u %u\n",bit,sum);
    for(i=idx;i<=n;i++)
    {
        fu=0;tot=0;sum=b4;tmp=1;
        if( 0!=(bit&(1<<(i-1) )) )
            continue;
        for(j=mclen;j>=1;j--)
        {
            if(a[i][j]+sum%10>=10)
            {
                fu=1;break;
            }
            tot+=tmp*(a[i][j]+sum%10);
            tmp*=10;
            sum/=10;
        }
        if(fu==0)
        {
            mc=max(mc,dp(bit|(1<<(i-1) ),idx+1,tot)+1);
        }
    }
    return jum[bit]=mc;
}
int main()
{
    unsigned int i,j,k;
    scanf("%u",&n);
    //memset(jum,-1,sizeof jum);
    for(i=1;i<=n;i++)
    {
        scanf("%s",str[i]+1);
        len[i]=strlen(str[i]+1);
        mclen=max(mclen,len[i]);
    }
//    for(i=1;i<=mclen;i++)
//    {
//        mcdec*=10;
//    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=mclen;j++)
        {
            a[i][mclen-len[i]+j]=str[i][j]-'0';
        }
    }
//    for(i=1;i<=n;i++)
//    {
//        for(j=1;j<=mclen;j++)
//        {
//            printf("%u",a[i][j]);
//        }
//        printf("\n");
//    }
    printf("%u",dp(0,1,0));
}
