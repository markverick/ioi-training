#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
int hsh[2200];
int a[2200];
int b[2200];
vector<int> jim[2200];
pair<int,int> p[2200];
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {

            scanf("%d %d",&a,&b);
            for(j=a;j<=b;j++)
            {
                hsh[j]++;
                jim[j].push_back(i);
            }
        }
    }
    for(i=0;i<=2000;i++)
    {
        p[i]=MP(hsh[i],i);
    }
    sort(&hsh[0],hsh[2000]);
    for(i=2000;i>=0;i--)
}

