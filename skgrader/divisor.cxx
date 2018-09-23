#include<bits/stdc++.h>
using namespace std;
int hsh[1000135][600];
int factor[1000135];
vector<int> pr;
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
        hsh[i][factor[i]]++;
    }
    while(T--)
    {
        scanf("%d %d %d",&x,&y,&d);
        printf("%d\n",upper_bound(&factor[x],&factor[1000001],d)-lower_bound(&factor[0],&factor[1000001],d) );
    }
}
