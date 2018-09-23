#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int hsh[25][63];
int main()
{
    int i,j,k,T,n,a,b,lst,id,mc=0,sum=0,mul=0;
    scanf("%d",&T);
    while(T--)
    {
        memset(hsh,0,sizeof hsh);
        scanf("%d",&n);
        mc=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&a,&b);
            hsh[a][b]++;
            mc=max(mc,hsh[a][b]);
        }
        printf("%d\n",mc);
    }
}
