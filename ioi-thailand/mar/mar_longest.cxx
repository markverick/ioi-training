#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int hsh[1000135];
int main()
{
    int n=0,i,j,k,a;
    while(135)
    {
        scanf("%d",&a);
        if(a==0)
            break;
        v.emplace_back(a);
        n++;
    }
    j=0;
    int mc=-1,fst,lst;
    for(i=0;i<n;i++)
    {
        hsh[v[i]]++;
        if(hsh[v[i]]>1)
        {
            while(hsh[v[i]]>1)
            {
                hsh[v[j++]]--;
            }
        }
        if(mc<i-j)
        {
            mc=i-j;
            fst=j;lst=i;
        }
    }
    for(i=fst;i<=lst;i++)
    {
        printf("%d\n",v[i]);
    }
}
