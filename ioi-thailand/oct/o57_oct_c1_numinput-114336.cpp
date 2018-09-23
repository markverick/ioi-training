#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1135],b[1135],c;
int num[1135];
int mn[1135],mc[1135];
int all=0;
int jum[1135][1135];
inline int dp(int idx,int sum)
{
    if(jum[idx][sum]>=0)
        return jum[idx][sum];
    if(idx==n-1)
    {
        //if(sum==all)
            return 1;
       // else
     //       return 0;
    }
    int sm=0;
    //printf("%d %d\n",idx,sum);
    for(int i=max(mc[idx+1],sum+1);i<min(mn[idx+2],all);i++)
    {
        sm+=dp(idx+1,i);
        sm%=9901;
    }
    return jum[idx][sum]=sm;
}
int pow(int b,int p)
{
    if(p==0)
        return 1;
    int tmp=(pow(b,p/2));
    tmp*=tmp;
    tmp%=9901;
    if(p%2)
        tmp*=b;
    tmp%=9901;
    return tmp;
}
int main()
{
    int i,j,k=1;
    memset(jum,-1,sizeof jum);
    scanf("%d %d",&n,&m);
    for(i=0;i<=n+3;i++)
    {
        mn[i]=1000000000;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        all+=a[i];
        for(j=1;j<=a[i];j++)
        {
            b[k++]=i;
        }
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&c);
        mc[b[c]]=max(mc[b[c]],c);
        mn[b[c]]=min(mn[b[c]],c);
    }
    if(m==0)
    {
        int prod=1,gook=1;
        for(i=all-1;i>=1;i--)
        {
            prod*=i;
            prod%=9901;
        }
        for(i=n-1;i>=1;i--)
        {
            gook*=i;
            gook%=9901;
        }
        for(i=all-1-(n-1);i>=1;i--)
        {
            gook*=i;
            gook%=9901;
        }
        prod=prod*pow(gook,9901-2);
        prod%=9901;
        printf("%d",prod);
        return 0;
    }

    printf("%d",dp(0,0));
}
