#include<bits/stdc++.h>
#define M 100000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[222];
long long n,ex=0;
char op[500],po[500];
long long jum[222][222];
long long dp(long long fst,long long lst)
{
    if(jum[fst][lst]>=0)
        return jum[fst][lst];
    if(lst+1==fst)
        return 1;
    if(lst-fst+1==1)
        return 0;
    long long sm=0,i;    for(i=fst+1;i<=lst;i+=2)
    {
        if(op[s[fst]]==s[i])
            sm+=dp(fst+1,i-1)*dp(i+1,lst);
        else if(s[fst]=='?'&&s[i]=='?')
            sm+=dp(fst+1,i-1)*dp(i+1,lst)*3;
        else if(s[fst]=='?'&&po[s[i]])
            sm+=dp(fst+1,i-1)*dp(i+1,lst);
        else if(s[i]=='?'&&op[s[fst]])
            sm+=dp(fst+1,i-1)*dp(i+1,lst);
    }
    if(sm>=M)
        ex=1,sm%=M;
    return jum[fst][lst]=sm;
}
int main()
{
    memset(jum,-1,sizeof jum);
	long long i,j,k;
	op['[']=']';
	op['{']='}';
	op['(']=')';
	po[']']='[';
	po['}']='{';
	po[')']='(';
	scanf("%lld %s",&n,s+1);
	k=dp(1,n);
	if(ex==0)
        printf("%lld",k);
    else
        printf("%05lld\n",k);
}
