#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[70];
double ncr[1135][1135];
double jum[1135][1135];
double dp(int head,int idx)
{
    if(jum[head][idx]>=0)
        return jum[head][idx];
    if(idx==k)
    {
        return (double)head;
    }
    //printf("=%d %d\n",head,idx);
    double sum=0.0,cot=0.0;
    int i;
    for(i=0;i<=a[idx+1];i++)
    {
        if(i<=head&&a[idx+1]-i<=n-head)
        {
            cot+=ncr[head][i]*ncr[n-head][a[idx+1]-i];
            sum+=dp(head-i+(a[idx+1]-i),idx+1)*ncr[head][i]*ncr[n-head][a[idx+1]-i];
        }
    }
//    for(i=0;i<=a[idx+1];i++)
//    {
//        if(n-head<a[idx+1]-i)
//            continue;
//        sum*=(head-i)/(n-i);
//        cot+=sum*dp(head-i+a[idx+1]-i,idx+1);
//    }
   // printf("=[%d][%d]=%f %f\n",head,idx,sum,cot);
    return jum[head][idx]=sum/cot;
}
int main()
{
    int T,i,j;
    ncr[0][0]=1;
    for(i=1;i<=1000;i++)
    {
        ncr[i][0]=1.0;
        for(j=1;j<=1000;j++)
        {
            ncr[i][j]=ncr[i][j-1]*(i+1-j)/j;
           //printf("%lf\n",ncr[i][j]);
        }
    }
    //printf("%f\n",ncr[5][2]);
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        memset(jum,-1,sizeof jum);
        for(i=1;i<=k;i++)
        {
            scanf("%d",&a[i]);
        }
        //cout << dp(n,0);
        printf("%f\n",dp(n,0));
    }
}
