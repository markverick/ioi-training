#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,all,a[22],jum[1100000];
int dp(int bit,int sum)
{
    if(sum==all)
    {
        return 1;
    }
    if(jum[bit]>=0)
        return jum[bit];
    int mc=0,i,j,fk=0;
    for(i=0;i<n;i++)
    {
        if(((1<<i)|bit)==bit)
            continue;
        for(j=1;j<=3;j++)
        {
            if(sum<j*all/4&&sum+a[i]>j*all/4)
                fk=1;
        }
        if(fk)continue;
        mc=max(mc,dp(bit|(1<<i),sum+a[i]));
    }
    return jum[bit]=mc;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int T,i,j,k,fk=0;
	scanf("%d",&T);
	while(T--)
    {
        memset(jum,-1,sizeof jum);
        scanf("%d",&n);all=0;fk=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            all+=a[i];
        }
        for(i=0;i<n;i++)
            if(a[i]>all/4)fk=1;
        if(all%4||fk)
            printf("no\n");
        else
        {
            if(dp(0,0))
                printf("yes\n");
            else
                printf("no\n");
        }
    }
}
