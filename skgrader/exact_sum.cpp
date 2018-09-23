#include<bits/stdc++.h>
using namespace std;

int a1[2000];
int a2[5000000];
map<long long,int> hsh;
int main()
{
    int i,j,k;
    int n,m;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a1[i]);
    }
    int idx=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a2[idx++]=a1[i]+a1[j];
            hsh[a1[i]+a1[j]]++;
        }
    }
    long long sum=0;
    for(i=0;i<idx;i++)
    {
        sum+=hsh[m-a2[i]];
    }
    printf("%lld",sum);
}
