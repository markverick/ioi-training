#include<bits/stdc++.h>
using namespace std;
int T,t,h,f;
int n[2135];
int jum[2135][2135];
vector<int> a[2135];
inline int dp(int idx,int tree)
{
    if(idx<=0)
        return 0;
    int mc=0,i,tt,t2;
    //printf("%d %d = %d\n",idx,tree,a[tree][idx]);
    if(jum[idx][tree]>=0)
        return jum[idx][tree];
    if(idx>0)
        mc=max(mc,dp(idx-1,tree)+1);
        //printf("%d %d");
    tt=a[tree][idx];
    for(i=1;i<=t;i++)
    {
        if(i==tree)
            continue;

        //printf("[%d] %d\n",i,tt-f);
        //system("pause");
        if(tt-f>0)
        {
            t2=upper_bound(a[i].begin(),a[i].end(),tt-f)-a[i].begin();
            if(t2>0)
            {
                mc=max(mc,dp(t2-1,i)+1);
            }

        }
    }
    return jum[idx][tree]=mc;
}
int main()
{
    int i,j,k,b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&t,&h,&f);
        memset(jum,-1,sizeof jum);
        for(i=0;i<=2000;i++)
        {
            a[i].clear();
        }
        for(i=1;i<=t;i++)
        {
            scanf("%d",&n[i]);
            //a[i].emplace_back(0);
            for(j=1;j<=n[i];j++)
            {
                scanf("%d",&b);
                a[i].emplace_back(b);
            }
                a[i].emplace_back(b);

            sort(a[i].begin(),a[i].end());
        }
        int mc=0;
        for(i=1;i<=t;i++)
        {
            if(!a[i].empty())
                mc=max(mc,dp(a[i].size()-1,i)+1);
            //printf("\n");
        }
        printf("%d\n",mc);
    }
}
