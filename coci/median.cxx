#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[100135];
int qa[100135],qb[100135];
int ha[200135],hb[200135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,m,id;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(m==a[i])
            id=i;
    }
    for(i=id-1;i>=1;i--)
    {
        if(a[i]>m)
            qa[i]=qa[i+1]+1;
        else
            qa[i]=qa[i+1]-1;
        ha[qa[i]+100000]++;
    }
    for(i=id+1;i<=n;i++)
    {
        if(a[i]>m)
            qb[i]=qb[i-1]+1;
        else
            qb[i]=qb[i-1]-1;
        hb[qb[i]+100000]++;
    }
    ha[100000]++;
    hb[100000]++;
    long long sm=0;
    for(i=-n;i<=n;i++)
    {
        sm+=ha[100000+i]*hb[100000-i];
    }
    printf("%lld",sm);
}
