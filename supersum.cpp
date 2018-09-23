#include<stdio.h>
#include<string.h>
int jum[20][20];
int ss(int k,int n)
{
    if(jum[k][n]>=0)
        return jum[k][n];
    if(k==0)
    {
        return n;
    }
    int sum=0;
    int i,j;
    for(i=0;i<=n;i++)
    {
        sum+=ss(k-1,n-i);
    }
    return jum[k][n] = sum;
}
int main()
{
    memset(jum,-1,sizeof jum);
    int a,b;
    while(scanf("%d %d",&b,&a)!=EOF)
    {
        printf("%d\n",ss(b,a));
    }
}
