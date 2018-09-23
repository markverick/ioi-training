#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int h[531],n,m;
vector<int> dp(int fst,int lst,int hi)
{
    int mn=MI,mc=0,x,y,i;
    vector<int> v,a,b;
    if(fst>lst)
        return v;
    v.resize(m+3,0);
    for(i=fst;i<=lst;i++)
    {
        if(mn>h[i]-hi)
            mn=h[i]-hi,x=i;
        mc=max(mc,h[i]-hi);
    }
    if(mn==0)
    {
        if(mn==mc)
        {
            v[0]=1;
            return v;
        }
        a=dp(fst,x-1,hi);
        for(i=x;i<=lst;i++)
        {
            if(h[i]-hi)
                break;
        }
        b=dp(i,lst)
    }

}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
    }
    dp(m,1,n);
}
