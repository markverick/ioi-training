#include<bits/stdc++.h>
using namespace std;
pair<int,int> dat[15005];
int fw[32005];
int hsh[15005];
int n;
inline void _add(int idx,int val)
{
    while(idx<=32001)
    {
        fw[idx]+=val;
        idx+=idx&-idx;
    }
}
inline int _sum(int idx)
{
    int sum=0;
    //printf("%d\n",idx);
    while(idx>0)
    {
        sum+=fw[idx];
        idx-=idx&-idx;
    }
    return sum;
}
int main()
{
    int i,j,k,a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        a++;b++;
        dat[i]={a,b};
    }
    sort(&dat[0],&dat[n]);
    int x,y,id;

    for(i=0;i<n;i++)
    {

        x=dat[i].first;
        y=dat[i].second;
        //printf("%d %d %d\n",x,y,id);
        hsh[_sum(y)]++;
        _add(y,1);
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",hsh[i]);
    }
}
