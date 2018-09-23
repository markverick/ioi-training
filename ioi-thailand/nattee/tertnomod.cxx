#include<bits/stdc++.h>
#define M 1000000007ll
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long pos[135],pr[135],in[135],p[135],mn[135][135],mc[135][135],jum[135][135];
long long dp(long long fs,long long ls)
{
//    printf("%lld - %lld\n",fs,ls);
    if(jum[fs][ls]>=0)return jum[fs][ls];
    if(fs==ls)
        return 1ll;
    long long k=0,cot=0,i;
    for(i=fs;i<=ls;i++)
    if(pos[in[i]]==mn[fs][ls])
        k=i;
    for(i=k+1;i<ls;i++)
    {
        if(mn[k+1][i]>mc[fs][k]&&mn[i+1][ls]>mc[k][i])
            cot+=(dp(k+1,i)*dp(i+1,ls))%M;
        cot%=M;
    }
//    if(ls-k>=2&&mn[k+1][ls]==pos[in[k+1]])
//        cot+=dp(k+2,ls);
//    if(ls-k>=2&&mc[k+1][ls]==pos[in[ls]])
//        cot+=dp(k+1,ls-1);
    if(k+1<=ls)
        cot+=dp(k+1,ls)*2;
    cot%=M;
    if(k>fs&&k<ls)
        return jum[fs][ls]=(dp(fs,k-1)*cot)%M;
    if(k>fs)
        return jum[fs][ls]=dp(fs,k-1)%M;
    return jum[fs][ls]=cot%M;

}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,i,j,k;
	memset(jum,-1,sizeof jum);
	scanf("%lld",&n);
	for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            mc[i][j]=0,mn[i][j]=MI;
	for(i=0;i<n;i++)
        scanf("%lld",&pr[i]),p[pr[i]]=i;
    for(i=0;i<n;i++)
        scanf("%lld",&in[i]),pos[in[i]]=p[in[i]];
    for(i=0;i<n;i++)
    {
//        printf("%lld ",pos[in[i]]);
        for(j=i+1;j<n;j++)
        {
            for(k=i;k<=j;k++)
                mn[i][j]=min(mn[i][j],pos[in[k]]),
                mc[i][j]=max(mc[i][j],pos[in[k]]);
        }
    }
//    printf("\n");
    printf("%lld",dp(0,n-1)%M);
}
