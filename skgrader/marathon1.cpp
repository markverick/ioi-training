#include<bits/stdc++.h>
using namespace std;
pair<int,int> dat[600];
pair<int,int> jum[600];
int hsh[600];
int main()
{
    int n,k;
    scanf("%d %d",&,&k);
    int i,j,k;
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&dat[i].first,&dat[i].second);
    }
    int mc=-999999999;
    int mn=999999999;
    int ans=-1;
    for(i=1;i<n-1;i++)
    {
        int a=abs(dat[i].first-dat[i-1].first)+abs(dat[i].second-dat[i-1].second)
                + abs(dat[i].first-dat[i+1].first)+abs(dat[i].second-dat[i+1].second);
        int b=abs(dat[i+1].first-dat[i-1].first)+abs(dat[i+1].second-dat[i-1].second);
        /*if(mc<a-b)
        {
            mc=a-b;
            ans=i;
        }*/
        jum[i]=make_pair(i,a-b);

    }
    sort(&jum[0],&jum[n]);
    for(i=n-1;i>n-1-k)
    {
        hsh[jum[i].first]=1;
    }
    //abs(dat[1].first-dat[0].first)+abs(dat[1].second-dat[0].second);
    //printf("%d",ans);
    int sum=0;
    //sort(&dat[0],&dat[n]);
    for(i=1;i<n-1;i++)
    {
        if(hsh[i]==1)
            dat[i]=dat[i-1];
    }
    for(i=1;i<n;i++)
    {
        sum+=abs(dat[i].first-dat[i-1].first)+abs(dat[i].second-dat[i-1].second);
    }
    printf("%d",sum);
}
