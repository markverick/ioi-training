#include<bits/stdc++.h>
using namespace std;

int x[120][22000];
int v[120];
int main()
{
    int i,j,k;
    int n;
    scanf("%d",&n);
    int sum=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
        v[i]+=101;
        sum+=v[i];
    }
    //for(i=0;i<=n;i++)
    //{
        x[0][0]=1;
    //}
    for(i=1;i<=n;i++)
    {
        for(j=n/2-1;j>=0;j--)
        {
            for(k=21000;k>=0;k--)
            {
                if(x[j][k]==1)
                    x[j+1][k+v[i]]=1;//printf("%d\n",j+1);
//
            }
        }
    }
    int mn=999999999;
    for(i=21000;i>=0;i--)
    {
        //int h=sum/2;
        if(x[n/2][i]==1)
            mn=min(mn,abs(sum-i-i));
    }
    printf("%d\n",mn);
}
