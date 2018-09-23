#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int mat[22],mas[22],n,m;
int jum[1100000];
int nxt[1100000];
int x[1100000],ED;
tuple<int,int,int> r[26];
int dp(int bit)
{
    if(jum[bit]>=0)
        return  jum[bit];
    int i,a,b,c,fk=0;
    if(__builtin_popcount(bit)==n)
    {
        ED=bit;
        return 1;
    }
    for(i=1;i<=m;i++)
    {
        tie(a,b,c)=r[i];
        if((1<<a)&bit)continue;
        if(((1<<b)&bit)&&((1<<c)&(~bit)))continue;
        if(((1<<c)&bit)&&((1<<b)&(~bit)))continue;
        fk|=(1<<a);
    }
    for(i=0;i<n;i++)
    {
        if((bit|(1<<i))==bit)continue;
        if((fk&(1<<i)))continue;
        if(dp(bit|(1<<i)))
        {
            nxt[bit]=bit|(1<<i);
            x[bit|(1<<i)]=i;
            return jum[bit]=1;
        }
    }
    return jum[bit]=0;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,c,a,b;
	memset(jum,-1,sizeof jum);
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c); ///a>b && c>a
        a--;b--;c--;
        r[i]=MT(a,b,c);
    }
    if(dp(0))
    {
        k=0;
        printf("YES\n");
        while(k!=ED)
        {
            k=nxt[k];
            printf("%d ",x[k]+1);
        }
    }
    else
        printf("NO\n");
}
