#include<bits/stdc++.h>
using namespace std;
int hsh[2000];
int main()
{
    int i,j,k,n,T;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&j);
        if(hsh[j%1007]==0)
        {
            printf("%d\n",j%1007);
        }
        hsh[j%1007]=1;
    }
}
