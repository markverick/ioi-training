#include<bits/stdc++.h>
using namespace std;
int a[531];
vector<int> x,y;
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(i%2==0)
            x.emplace_back(a[i]);
        else
            y.emplace_back(a[i]);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int sum=0;
    for(i=0;i<x.size();i++)
    {
        sum+=abs(x[i]-y[y.size()-i-1]);
    }
    printf("%d",sum);
}
