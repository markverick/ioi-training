#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int ft[100135],h[100135],out[100135],broken[100135];
int n,m;
pair<int,int> p[100135];
vector<int> v;
vector<int> lst[100135];
void add(int idx,int val)
{
    while(idx<=1000000000)
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
        sm+=idx&-idx;
    }
    return sm;
}
int main()
{
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
        v.emplace_back(h[i]-h[i-1]);
    }
    sort(v.begin(),v.end());
    auto it=unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));
//    for(i=0;i<v.size();i++)
//    {
//        printf("= %d\n",v[i]);
//    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&p[i].X);
        p[i].Y=i;
    }
    sort(&p[1],&p[m+1]);
    j=v.size()-1;
    int lv=0,cot=0;
    for(i=m;i>=1;i--)
    {
        //printf("%d %d\n",p[i].X,v[j]);
        if(p[i].X<v[j])
        {
            while(p[i].X<v[j])
                j--;
            lv=h[1];
            for(k=2;k<=n;k++)
            {
                if(h[k]-lv>p[i].X)
                {
                    if(broken[k]==0)
                    {
                        broken[k]=1;
                        cot++;
                    }
                }
                else
                {
                    lv=h[k];
                }
            }
            j++;
       }
       out[p[i].Y]=cot;
    }
    for(i=1;i<=m;i++)
    {
        printf("%d\n",out[i]);
    }
}
