#include<bits/stdc++.h>
using namespace std;
int n,k;
long long x[20],y[100135];
long long z[100135];
int fin;
int Max=0;
long long xsum=0;
inline int bs(int fst,int cap)
{
    int mid;
    int lst=n;
    int pos=fst;
    int mc=fst;
    while(fst<=lst)
    {
        mid=(fst+lst)/2;
        if(z[mid]-z[pos-1]>cap)
        {
            lst=mid-1;
        }
        else
        {
            mc=max(mc,mid);
            fst=mid+1;
        }
    }
    return mc;
}
unordered_map<int,int> jum[140000];
int dp(int bit,int prog)
{
    if(jum[bit].find(prog)!=jum[bit].end())
        return jum[bit][prog];
    //printf("%d %d\n",bit,prog);
    //system("pause");
    if(prog>=n||bit==fin)
        return xsum;
    int i,j;
    int tmp=bit;
    int dest;
    long long mc=0;
    for(i=1;i<=k;i++)
    {
        if((tmp|(1<<(i-1)))!=tmp)
        {
            //bs(prog+1,prog+1,n,x[i]);
            //if((tmp| (1<<(i-1)))==fin)
            dest=bs(prog+1,x[i]);

            mc=max(mc,dp(tmp^ (1<<(i-1)),dest)-x[i]);
        }
    }
    //printf("bit[%d] = %d\n",bit,mc);
    return jum[bit][prog]=mc;
}
int main()
{
    int i,j;
    scanf("%d %d",&k,&n);
    fin=(1<<k)-1;
    for(i=1;i<=k;i++)
    {
        scanf("%lld",&x[i]);
        xsum+=x[i];
    }
    //printf("%d\n",xsum);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&y[i]);
        z[i]=z[i-1]+y[i];
    }
    //memset(jum,-1,sizeof jum);
    long long omelet=dp(0,0);
    int sum=0;
    /*for(i=n;i>omelet;i--)
    {
        sum+=y[i];
    }*/
    printf("%lld",omelet);
}
