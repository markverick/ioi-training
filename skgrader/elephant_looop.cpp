#include<bits/stdc++.h>
using namespace std;
int maps[120000];
int n;
int jum[120000];

int main()
{
    memset(jum,-1,sizeof(jum));
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {

        scanf("%d",&maps[i]);
    }
    jum[0]=0;
    jum[1]=0;
    for(i=2;i<n;i++)
    {
        jum[i]=max(jum[i-3]+maps[i],jum[i-1]);
    }
    /*for(i=n-1;i>=0;i--)
    {
        omelet(i);
    }*/
    printf("%d",jum[n-1]);
}
