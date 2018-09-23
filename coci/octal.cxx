#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[135],t[135];
int main()
{
	int i,j,k,len;
	scanf("%s",s);
	len=strlen(s);
	j=0;
	for(i=len-1;i>=0;i--)
    {
        t[j++]=s[i]-'0';
    }
    len=(((len-1)/3)+1)*3;
    vector<int> v;
    for(i=len-1;i>=0;i-=3)
    {
        k=0;
        for(j=i;j>i-3;j--)
        {
            k*=2;k+=t[j];
        }
        printf("%d",k);
    }
}
