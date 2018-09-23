#include "tourist.h"
/*
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
*/
int GreaterHappiness(int N, int K, int *H){

    int n=N,k=K,c;
    int i,j;

    int sum=0;
    if(k>=n)
    {
        c=k-n;
        sort(&H[0],&H[n]);
        for(i=n-1;i>=n-c-1;i--)
        {
            sum+=H[i];
        }
        printf("%d",sum);
    }

    else
    {
        c=k/2;
        for(i=0;i<=c;i++)
        {
            sum+=H[i];
        }
        printf("%d",sum);
    }

    return 0;
}
/*int h[1200000];
int main()
{
    int n,k,i;
    scanf("%d %d",&n,&k);

    for(i=0;i<n;i++)
    {
        scanf("%d",&h[i]);
    }
    GreaterHappiness(n,k,h);
}*/
