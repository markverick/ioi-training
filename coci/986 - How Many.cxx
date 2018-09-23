#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,pk,ed;
int jum[44][84][3][22];
int dp(int idx,int h,int bl,int rem)
{
    if(jum[idx][h][bl][rem]>=0)
        return jum[idx][h][bl][rem];
    if(idx==n)
    {
//        printf("%d %d %d %d\n",idx,h,bl,rem);
        if(h==0&&rem==0)
        {
            return 1;
        }
        return 0;
    }
    int sum=0;
    if(bl==0)
    {
        if(h)
        {
            if(h==ed&&rem)
                sum+=dp(idx+1,h-1,1,rem-1);
            if(h!=ed)
                sum+=dp(idx+1,h-1,1,rem);
        }
        sum+=dp(idx+1,h+1,0,rem);
    }
    else
    {
        sum+=dp(idx+1,h+1,0,rem);
        if(h)
            sum+=dp(idx+1,h-1,1,rem);
    }
    return jum[idx][h][bl][rem]=sum;
}
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	while(scanf("%d %d %d",&n,&pk,&ed)!=EOF)
	{
	    memset(jum,-1,sizeof jum);
	    n=n*2+1;
        printf("%d\n",dp(1,0,0,pk));
	}
}
