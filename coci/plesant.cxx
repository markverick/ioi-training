#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long n,vow[500];
char res[135],s[135];
long long gen(long long idx)
{
    if(idx==n)
    {
        long long i;
        for(i=1;i<n-1;i++)
        {
            if(vow[res[i]]==vow[res[i+1]]&&vow[res[i]]==vow[res[i-1]])
                return 0;
        }
        for(i=0;i<n;i++)
            if(res[i]=='L')
                return 1;
        return 0;
    }
    long long sum=0;
    if(s[idx]=='_')
    {
        res[idx]='A';
        sum+=gen(idx+1)*5;
        res[idx]='B';
        sum+=gen(idx+1)*20;
        res[idx]='L';
        sum+=gen(idx+1);
    }
    else
    {
        res[idx]=s[idx];
        sum=gen(idx+1);
    }
    return sum;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k;
	vow['A']=1;
	vow['E']=1;
	vow['I']=1;
	vow['O']=1;
	vow['U']=1;
	scanf("%s",s);
	n=strlen(s);
	printf("%lld",gen(0));
}
