#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char ch[12][3];
long long a[12],hsh[12],fk[500];
vector<pair<double,long long> > v;
pair<char,long long> p[12];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,i,j,k,all;
	scanf("%lld %lld",&all,&n);
	for(i=1;i<=n;i++)
    {
        scanf("%s %lld",ch[i],&a[i]);
        if(a[i]*100<5*all)
            fk[ch[i][0]]=1;
        for(j=1;j<=14;j++)
            v.emplace_back(-((double)a[i])/j,i);
    }
    sort(v.begin(),v.end());
    for(i=0;i<14;i++)
    {
        hsh[v[i].Y]++;
    }
    for(i=1;i<=n;i++)
        p[i]=MP(ch[i][0],hsh[i]);
    sort(&p[1],&p[n+1]);
    for(i=1;i<=n;i++)
    {
        if(fk[p[i].X])continue;
        printf("%c %lld\n",p[i].X,p[i].Y);
    }
}
