#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char str[1135];
int a[33],hsh[6135],jum[33][33][3][6010],n,C=0;
string op[33];
int dp(int idx,int lv,int o,int sum)
{
    if(idx==n)
    {
        if(hsh[sum+3000]==0)
            C++,hsh[sum+3000]=1;
        return 1;
    }
    if(jum[idx][lv][o][sum+3000]>=0)
        return jum[idx][lv][o][sum+3000];
    int mc=0,sg=1;
    if(o)sg=-1;
    if(op[idx+1][0]=='+')
    {
        mc=max(mc,dp(idx+1,lv,o,sum+sg*a[idx+1]));
//        cot+=dp(idx+1,lv+1,o,sum+sg*a[idx+1]);
    }
    else
    {
        mc=max(mc,dp(idx+1,lv,o,sum-sg*a[idx+1]));        mc=max(mc,dp(idx+1,lv+1,1-o,sum-sg*a[idx+1]));
    }
    if(lv)
    {
        mc=max(mc,dp(idx,lv-1,1-o,sum));
    }
    return jum[idx][lv][o][sum+3000]=mc;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,len;
    while(gets(str))
    {
        memset(jum,-1,sizeof jum);
        memset(hsh,0,sizeof hsh);
        stringstream ss;
        ss << str;
        ss>>a[1];
        n=2;
        C=0;
        while(ss>>op[n]>>a[n])
            n++;
        n--;
        dp(1,0,0,0);
        printf("%d\n",C);
    }
}
