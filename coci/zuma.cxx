#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[135],jum[135][135][8],n,m;
int dp(int fst,int lst,int ex)
{
    int f=fst,l=lst,e=ex;
//    if(jum[fst][lst][ex]>=0)
//        return jum[fst][lst][ex];
    while(fst<lst)
    {
        if(a[fst+1]==a[f])
            fst++,ex++;
        else
            break;
    }
    if(fst==lst)
        return max(0,m-ex-1);
    if(jum[fst][lst][ex]>=0)
        return jum[fst][lst][ex];
//    printf("%d %d %d\n",fst,lst,ex);
//    system("pause");
    int i,j=0,mn=1000000000;
    if(ex+1>=m)
        mn=min(mn,dp(fst+1,lst,0));
    else
        mn=min(mn,dp(fst,lst,ex+1)+1);
    for(i=fst+1;i<=lst;i++)
    {
        if(a[i]==a[fst])
        {
            mn=min(mn,dp(fst+1,i-1,0)+dp(i,lst,ex+1));
        }
    }
    return jum[fst][lst][ex]=jum[f][l][e]=mn;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	memset(jum,-1,sizeof jum);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
//    printf("%d\n",dp(2,4,0));
    printf("%d",dp(1,n,0));
}
