#include<bits/stdc++.h>
using namespace std;
int a[120000];
int hsh[120000];
int main()
{
    int T,t,i,j,k,n;
    int sum=0;
    int ave=0;
    scanf("%d",&T);

    for(t=0;t<T;t++)
    {
        memset(hsh,0,sizeof hsh);
        memset(a,0,sizeof a);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            hsh[a[i]]++;
        }
        int hi=0;
        for(i=0;i<n;i++)
        {
            hi=max(hi,hsh[a[i]]);
        }
        printf("%d\n",n-hi);

    }
}
