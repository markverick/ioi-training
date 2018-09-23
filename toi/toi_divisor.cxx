#include<bits/stdc++.h>
using namespace std;
vector<int> hsh[505];
int factor[1000135];
int cot;
int main()
{
    int T,x,y,d,c,i,j,hi=0;
    scanf("%d",&T);
    for(i=1;i<=1000000;i++)
    {
        for(j=i;j<=1000000;j+=i)
            factor[j]++;
    }
    for(i=1;i<=1000000;i++)
    {
        hsh[factor[i]].emplace_back(i);
    }
    for(i=1;i<=300;i++)
    {
        sort(hsh[i].begin(),hsh[i].end());
    }
    while(T--)
    {
        scanf("%d %d %d",&x,&y,&d);
        if(d>300)
        {
            printf("0\n");
        }
        else
            printf("%d\n",upper_bound(hsh[d].begin(),hsh[d].end(),y)-lower_bound(hsh[d].begin(),hsh[d].end(),x));
    }
}
