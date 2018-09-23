#include<bits/stdc++.h>
using namespace std;
//pair<int,int> x[100135];
int qs[1000135];
int sum=0;
int main()
{
    int n,i,j,a,b,mc=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        //x[i]={a,b};
        mc=max(mc,b+1);
        qs[a]++;qs[b+1]--;
    }
    int mx=0;
    for(i=0;i<=mc+1;i++)
    {
        sum+=qs[i];
        mx=max(mx,sum);
    }
    if(mx>=n)
    {
        printf("no");
    }
    else
        printf("yes");
}
