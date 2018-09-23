#include<bits/stdc++.h>
using namespace std;
int a[100135],n,jum[10135][10135];
vector<int> v;
int dp(int dist,int dif)
{
    if(dist==0)
    {
        if(dif==0)
            return 1;
        else
        {
            printf("FAILED\n");
            return 0;
        }
    }
    int sum=0;
    if(dist+1<=abs(dif))
    {
        return 0;
    }
    if(dif>0)
    {
        sum+=dp(dist-1,dif-1);
        if(dif+2<=dist)
        {
            sum+=dp(dist-1,dif+1);
        }
    }
    else if(dif<0)
    {
        sum+=dp(dist-1,dif+1);
        if(dif-2>=-dist)
        {
            sum+=dp(dist-1,dif-1);
        }
    }
    else
    {
        if(dist>1)
            sum+=dp(dist-1,-1)+dp(dist-1,1);
    }
    if(abs(dif)+1<=dist)
    {
        sum+=dp(dist-1,dif);
    }
    return sum;
}
int main()
{
    int i,j,k,n,a,cot=1,b,sum=0;
    scanf("%d",&n);
    b=0;
    printf("%d\n",dp(2,0));
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(i==1||i==n)
        {
            if(a>0)
            {
                printf("0");
                return 0;
            }
            continue;
        }
        if(a==-1)
        {
            cot++;
        }
        else
        {
            sum+=dp(cot,abs(b-a));
            b=a;
            cot=1;
        }
    }
    sum+=dp(cot,abs(b));
    printf("%d",sum);
}
