#include<bits/stdc++.h>
using namespace std;
map<int,bool> hsh;
int out[120000];
int idx=0;int a,b;
int main()
{
    int n,m;
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        hsh[a]=1;
    }
    idx=0;
    for(i=0;i<m;i++)
    {
        scanf("%d",&a);
        if(a-999>=1&&hsh[a-999]==1)
        {
            out[idx++]=a;
        }
    }
    if(idx==0)
        printf("No");
    else
    {
        printf("%d\n",idx);
        for(i=0;i<idx;i++)
        {
            printf("%d\n",out[i]);
        }
    }
}
