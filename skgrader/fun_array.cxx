#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int a[1000135];
int c[1000135];
deque<pair<int,int> > deq;
int main()
{
    int n,m,i,j,k=1,mn=1000000000,mc=0,sum=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(&a[1],&a[n+1]);
    for(i=1;i<n;i++)
    {
        c[i]=a[i+1]-a[i];
    }
    for(i=1;i<n-m;i++)
    {
        sum+=c[i];
//        printf("%d %d\n",i,sum);
        while(!deq.empty()&&c[i]<=deq.back().X)
        {
            deq.pop_back();
        }
        deq.emplace_back(c[i],i);
    }
    mn=min(mn,sum+deq.front().X);
//    printf("Max = %d Min = %d\n",sum,deq.front().X);
    for(i=n-m;i<n;i++)
    {
        sum+=c[i];
        while(!deq.empty()&&c[i]<=deq.back().X)
        {
            deq.pop_back();
        }
        deq.emplace_back(c[i],i);
        if(!deq.empty()&&i-n+m+1==deq.front().Y)
        {
            deq.pop_front();
        }
        sum-=c[i-n+m+1];
        mn=min(mn,sum+deq.front().X);
    }
    printf("%d",mn);
}
