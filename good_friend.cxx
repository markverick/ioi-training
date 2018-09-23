#include<bits/stdc++.h>
using namespace std;
char s[25];
long long a[300135];
long long hsh[25];
int main()
{
    long long n,m,i,j,k,cot=0;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%s",s);
        a[i]=strlen(s);
    }
    for(i=1;i<=m+1;i++)
    {
        cot+=hsh[a[i]];
        hsh[a[i]]++;
    }
    for(i=m+2;i<=n;i++)
    {
        hsh[a[i]]++;
        hsh[a[i-m-1]]--;
        cot+=hsh[a[i]]-1;
    }
    printf("%lld",cot);
}
