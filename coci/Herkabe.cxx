#include<bits/stdc++.h>
#define M 1000000007
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
string s[3135];
int n,len=0;
long long fac[3135];
long long dp(int fs,int ls,int lv)
{
    if(fs==ls)
        return 1;
    int i,j,k=1;
    long long prod=1;
    j=fs;
    for(i=fs+1;i<=ls;i++)
    {
        if(s[i][lv]!=s[i-1][lv])
        {
            prod*=dp(j,i-1,lv+1);
            prod%=M;
            j=i;
            k++;
        }
    }
    prod*=dp(j,ls,lv+1);
    prod%=M;
    prod*=fac[k];
    prod%=M;
    return prod;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	cin >>n;
	fac[0]=1;
	for(i=1;i<=3000;i++)
        fac[i]=fac[i-1]*i,fac[i]%=M;
	for(i=1;i<=n;i++)
    {
        cin >>s[i];
        len=max(len,(int)s[i].size());
    }
    sort(&s[1],&s[n+1]);
    for(i=1;i<=n;i++)
    {
        s[i].resize(len,0);
    }
    printf("%lld\n",dp(1,n,0));
}
