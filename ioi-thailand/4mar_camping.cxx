#include<bits/stdc++.h>
using namespace std;
int hsh[3000135];

int main()
{
    int n,i,j,k;
    scanf("%d %d",&n,&k);
    for(i=1;i<=k;i++)
    {
        scanf("%d %d %d %d",&x,&y,&a,&b);
        for(j=1;j<=x;j++)
        {
            hsh[a*j+b]++;
        }
    }
}
