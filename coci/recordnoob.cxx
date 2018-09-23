#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[222];
int n;
char op[500],po[500];
int dp(int fst,int lst)
{
    if(lst-fst+1==1)
        return 0;
    else if(lst-fst+1==2)
    {
        if(op[s[fst]]==s[lst])
            return 1;
        else if(s[fst]=='?'&&s[lst]=='?')
            return 3;
        else if(s[fst]=='?'&&po[s[lst]])
            return 1;
        else if(s[lst]=='?'&&op[s[fst]])
            return 1;
        else
            return 0;
    }
    int mc=0,i;
    for(i=fst+1;i<lst-1;i++)
    {
        mc=max(mc,dp(fst,i)*dp(i+1,lst));
    }
    if(op[s[fst]]==s[lst])
        mc=max(mc,dp(fst+1,lst-1));
    else if(s[fst]=='?'&&s[lst]=='?')
        mc=max(mc,dp(fst+1,lst-1)*3);
    else if(s[fst]=='?'&&po[s[lst]])
        mc=max(mc,dp(fst+1,lst-1));
    else if(s[lst]=='?'&&op[s[fst]])
        mc=max(mc,dp(fst+1,lst-1));
    return mc;
}
int main()
{
	int i,j,k;
	op['[']=']';
	op['{']='}';
	op['(']=')';
	po[']']='[';
	po['}']='{';
	po[')']='(';
	scanf("%d %s",&n,s+1);
	printf("%d",dp(1,n));
}
