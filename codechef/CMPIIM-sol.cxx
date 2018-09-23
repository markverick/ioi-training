#include<bits/stdc++.h>
using namespace std;
const int N=1250*1250 +1;
int a[N];
int main()
{
    for(int i=1;i<N;i++)
        for(int j=i;j<N;j+=i)
            a[j]++;
    for(int i=1;i<N;i++)
        a[i]+=a[i-1];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        long long int ans=0;
        for(int d=1;d<n;d++)
            ans+=a[d*(n-d)-1];
        cout<<ans<<"\n";
    }
    return 0;
}
