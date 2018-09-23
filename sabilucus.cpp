#include<bits/stdc++.h>
using namespace std;
long long sum[1200][1200];
priority_queue<long long> out;
int main()
{
    int r,c,n;
    int i,j,k,a;
    scanf("%d %d %d",&r,&c,&n);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            scanf("%d",&a);
            sum[i][j]=sum[i-1][j]-sum[i-1][j-1]+sum[i][j-1]+a;
            //printf("%d ",sum[i][j]);
        }
        //printf("\n");
    }
    //int hi=0,lo=0;
    for(i=0;i<=r-n;i++)
    {
        for(j=0;j<=c-n;j++)
        {
            //printf("%d\n",sum[i+n][j+n]-sum[i][j+n]-sum[i+n][j]+sum[i][j]);
            out.push(sum[i+n][j+n]-sum[i][j+n]-sum[i+n][j]+sum[i][j]);
            /*if(hi<sum[i+n][j+n]-sum[i][j+n]-sum[i+n][j]+sum[i][j])
            {
                hi=sum[i+n][j+n]-sum[i][j+n]-sum[i+n][j]+sum[i][j];
            }*/
        }
    }
    long long temp=out.top();
    printf("%lld\n",out.top());out.pop();
    while(out.empty()==0&&out.top()==temp)
        out.pop();
    if(!out.empty())
        printf("%lld",out.top());
    else
        printf("0");
}
