#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int h[1200000];
int main()
{

    int n,k,c;
    int i,j;
    scanf("%d %d",&n,&k);

    for(i=0;i<n;i++)
    {
        scanf("%d",&h[i]);

    }
    int sum=0;
    if(k>n)
    {
        c=k-n;
        sort(&h[0],&h[n]);
        for(i=n-1;i>=n-c-1;i--)
        {
            sum+=h[i];
        }
        printf("%d",sum);
    }

    else
    {
        c=k/2;
        for(i=0;i<=c;i++)
        {
            sum+=h[i];
        }
        printf("%d",sum);
    }


}
