#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char a[20],b[20],s[20];
long long len,n,mn=-1;
long long jum[20][140][5];
long long dp(long long idx,long long sum,long long bd,long long val)
{
//    printf("%lld %lld %lld %lld\n",idx,sum,bd,val);
    if(jum[idx][sum][bd]>=0)
        return jum[idx][sum][bd];
    if(idx==len)
    {
        if(sum==n)
        {
            if(mn==-1)
                mn=val;
            return 1;
        }
        return 0;
    }
    long long i,sm=0;
    if(bd==3)
    {
        if(a[idx]==b[idx])
            sm+=dp(idx+1,sum+a[idx],3,val*10+a[idx]);
        else
        {
            sm+=dp(idx+1,sum+a[idx],1,val*10+a[idx]);
            for(i=a[idx]+1;i<b[idx];i++)
                sm+=dp(idx+1,sum+i,0,val*10+i);
            sm+=dp(idx+1,sum+b[idx],2,val*10+b[idx]);
        }
    }
    else if(bd==2)
    {
        for(i=0;i<b[idx];i++)
            sm+=dp(idx+1,sum+i,0,val*10+i);
        sm+=dp(idx+1,sum+b[idx],2,val*10+b[idx]);
    }
    else if(bd==1)
    {
        sm+=dp(idx+1,sum+a[idx],1,val*10+a[idx]);
        for(i=a[idx]+1;i<=9;i++)
            sm+=dp(idx+1,sum+i,0,val*10+i);
    }
    else
    {
        for(i=0;i<=9;i++)
            sm+=dp(idx+1,sum+i,0,val*10+i);
    }
    return jum[idx][sum][bd]=sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	memset(jum,-1,sizeof jum);
	long long A,B,i,j,k,L,R;
	scanf("%s %s %lld",a,b,&n);
	A=strlen(a);
	B=strlen(b);
	len=max(A,B);
	for(i=0;i<A;i++)
        s[i+len-A]=a[i]-'0';
    for(i=0;i<len;i++)
        a[i]=s[i];
//    for(i=0;i<len;i++)
//        printf("%lld ",s[i]);
//    printf("\n");
	for(i=0;i<B;i++)
        s[i+len-B]=b[i]-'0';
    for(i=0;i<len;i++)
        b[i]=s[i];
//    for(i=0;i<len;i++)
//        printf("%lld ",s[i]);
//    printf("\n");
    printf("%lld\n",dp(0,0,3,0));
    printf("%lld",mn);
}
