#include<bits/stdc++.h>
using namespace std;
int n,m,cap=0;
int v[1200];
int w[1200];
int kp(int idx,int cap)
{
    if(idx==0)
    {
        return v[0];
    }
    else
    {
        return max(kp(idx-1,cap-w[idx])+v[idx],kp(idx-1,cap));
    }
}
int main()
{
    int t,T,i,j,k;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        memset(v,0,sizeof v);
        memset(w,0,sizeof w);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&v[i],&w[i]);
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&cap);
            printf("%d\n",kp(m,cap));
        }
    }
}
