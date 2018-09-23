#include<bits/stdc++.h>
using namespace std;
int num[250];
int a;
int omelet(int idx,int cap)
{
    if(idx==0)
    {
        return v[0];
    }
    else
    {
        return max(omelet(idx-1,cap-w[idx])+v[idx],omelet(idx-1,cap));
    }
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int i,j;
        for(i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        for(j=0;j<m;j++)
        {
            scanf("%d",&a)
        }
    }
}
