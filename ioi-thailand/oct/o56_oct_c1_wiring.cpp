#include<bits/stdc++.h>
using namespace std;
int x[100135],y[100135],a[100135],b[100135],ft[100135],fu=0;
int n;
vector<pair<int,int> > v;
void add(int idx,int val)
{
    while(idx<=n)
    {
        ft[idx]+=val;
        idx+=idx&-idx;
    }
}
int sum(int idx)
{
    int sm=0;
    while(idx>0)
    {
        sm+=ft[idx];
        idx-=idx&-idx;
    }
    return sm;
}
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);fu=0;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(x,0,sizeof x);
        memset(y,0,sizeof y);
        memset(ft,0,sizeof ft);
        v.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
        }
        for(i=1;i<=n;i++)
        {
            if(a[i]==b[i])continue;
            if(a[i]==0||b[i]==0)
                continue;
            x[a[i]]=i;
            y[b[i]]=i;
        }
        for(i=1;i<=n;i++)
        {
            if(x[i]>0&&y[i]>0)
            {
                v.emplace_back(-x[i],y[i]);
            }
        }
        sort(v.begin(),v.end());
        int cot=0;
        for(i=0;i<v.size();i++)
        {
            cot+=sum(v[i].second);
            add(v[i].second,1);
        }
        if(cot>0)
            printf("NO\n");
        else
            printf("YES\n");
    }
}
