#include<bits/stdc++.h>
using namespace std;
int a[33];
int kp[555],hsh[555];
int main()
{
    int n,r,c,i,j,k;
    scanf("%d %d %d",&n,&r,&c);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<=r)
            kp[a[i]]=1;
    }
    vector<int> v;
    v.emplace_back(1);
    v.emplace_back(r);
    v.emplace_back(r+c-1);
    v.emplace_back(r+c+r-2);
    v.emplace_back(r+c+r+c-3);
    v.emplace_back(1000000000);
    int lv1,lv2;
    for(i=1;i<=2*(r+c)-4;i++)
    {
        lv1=upper_bound(v.begin(),v.end(),i)-v.begin();lv1--;
        for(j=1;j<=n;j++)
        {
            if(a[j]>max(r,c))
                continue;
            lv2=upper_bound(v.begin(),v.end(),i+a[j])-v.begin();lv2--;
            if(lv1==lv2)
            {
                kp[i+a[j]]+=kp[i];
                kp[i+a[j]]%=9661;
            }
            else if(v[lv2]==i+a[j]&&lv2==lv1+1)
            {
                kp[i+a[j]]+=kp[i];
                kp[i+a[j]]%=9661;
            }
            else if(i==v[lv1+1]-1&&i+a[j]<=v[lv1+2])
            {
                kp[i+a[j]]+=kp[i];
                kp[i+a[j]]%=9661;
            }
        }
    }
    int sum=kp[(r+c)*2-4];
    v.clear();
    v.emplace_back(1);
    v.emplace_back(c);
    v.emplace_back(c+r-1);
    v.emplace_back(c+r+c-2);
    v.emplace_back(c+r+c+r-3);
    v.emplace_back(1000000000);
    memset(kp,0,sizeof kp);
    for(i=1;i<=n;i++)
    {
        if(a[i]>1&&a[i]<=c)
            kp[a[i]]=1;
    }
    for(i=1;i<=2*(r+c)-4;i++)
    {
        lv1=upper_bound(v.begin(),v.end(),i)-v.begin();lv1--;
        for(j=1;j<=n;j++)
        {
            if(a[j]>max(r,c))
                continue;
            lv2=upper_bound(v.begin(),v.end(),i+a[j])-v.begin();lv2--;
            if(lv1==lv2)
            {
                kp[i+a[j]]+=kp[i];
                kp[i+a[j]]%=9661;
            }
            else if(v[lv2]==i+a[j]&&lv2==lv1+1)
            {
                kp[i+a[j]]+=kp[i];
                kp[i+a[j]]%=9661;
            }
            else if(i==v[lv1+1]-1&&i+a[j]<=v[lv1+2])
            {
                kp[i+a[j]]+=kp[i];
                kp[i+a[j]]%=9661;
            }
        }
    }
    printf("%d\n",(sum+kp[(r+c)*2-4])%9661);
}
