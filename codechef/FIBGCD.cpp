#include<bits/stdc++.h>
using namespace std;
int jum[1200000];
int gcd ( int a, int b )
{
    int c;
    while(a!=0)
    {
     c=a;a=b%a;b=c;
    }
    return b;
}
int fib(int n)
{
    if(jum[n]!=0)
    {
        return jum[n];
    }
    if(n==1)
        return 1;
    if(n==2)
        return 1;
    return jum[n]=(fib(n-1)+fib(n-2))%1000000007;
}
int main()
{
    int t;
    int i,j,k,a,b,c;
    scanf("%d",&t);
    jum[0]=0;jum[1]=1;jum[2]=1;
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&a,&b);
        c = gcd(a,b);
        printf("%d\n",fib(c));

    }
}
