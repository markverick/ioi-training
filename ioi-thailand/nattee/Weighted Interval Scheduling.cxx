#include<bits/stdc++.h>
#define MI 1000000005
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
tuple<int,int,int> v[1135];
int n,tma[1135],jum[1135];
int dp(int idx,int ls)
{
    if(idx==n+1)
    {
        return 0;
    }
    if(jum[idx]>=-1)
        return jum[idx];
    int mc=-1,i,x,y,w,k=0,j=0;
    for(i=idx+1;i<=n+1;i++)
    {
        tie(x,y,w)=v[i];
        if(x>=ls)
        {
            k=dp(i,y)+w;
            if(mc<k)
                mc=k,j=i;
        }
    }
    tma[idx]=j;
    return jum[idx]=mc;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,a,b,c;
	scanf("%d",&n);
	for(i=0;i<=n+1;i++)
        jum[i]=-2;
	v[0]=MT(-1,-1,0);
	for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        v[i]=MT(a,b,c);
    }
    v[n+1]=MT(MI,MI,0);
    sort(&v[1],&v[n+1]);
    printf("%d\n",dp(0,-1));
    i=tma[0];
    vector<int> o;
    while(i<=n)
    {
        o.emplace_back(i);
        i=tma[i];
    }
    printf("%d\n",o.size());
    for(i=0;i<o.size();i++)
        printf("%d ",o[i]);
}
