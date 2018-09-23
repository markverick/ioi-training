#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back;
using namespace std;
int a[1135],b[1135];
int main()
{
    int i,j,k,n,m,x,y,sum,fu;
    double baw;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(m--)
    {
        sum=0;
        scanf("%d %d %lf",&x,&y,&baw);
        for(i=x;i<=y;i++)
        {
            b[i]=a[i];
            sum+=a[i];
        }
        sort(&b[x],&b[y+1]);
        fu=0;
        for(i=x;i<=y;i++)
        {
            if((double)sum/(y-i+1)>=baw)
            {
                fu=i-x+1;
                break;
            }
            sum-=b[i];
        }
        printf("%d\n",fu-1);
    }
}
