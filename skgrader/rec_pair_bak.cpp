#include<bits/stdc++.h>
#define MP make_pair
using namespace std;
int mat[55][55];
int sum[55][55];
int jum[55][55][55][55];
map<pair<int,pair<int,int> >,int> ha[55][55];
map<int,int> hsh[55][55];
int main()
{
    int n;
    scanf("%d",&n);
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            int a;
            scanf("%d",&a);
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a;
        }
    }
    int l;
    int mc=-2147483646;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=i;k<=n;k++)
            {
                for(l=j;l<=n;l++)
                {
                    hsh[i][j][sum[k][l]-sum[k][j-1]-sum[i-1][l]+sum[i-1][j-1]]++;
                    ha[i][j][MP(sum[k][l]-sum[k][j-1]-sum[i-1][l]+sum[i-1][j-1],MP(k,l))]++;
                }
            }
        }
    }
    int ans=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=i;k<=n;k++)
            {
                for(l=j;l<=n;l++)
                {
                    int a=hsh[i][j][sum[k][l]-sum[k][j-1]-sum[i-1][l]+sum[i-1][j-1]];
                    if(ha[i][j][MP(sum[k][l]-sum[k][j-1]-sum[i-1][l]+sum[i-1][j-1],MP(k,l))]>0)
                        a--;
                    if(a>=2)
                    {
                        //printf("%d\n",a*(a-1));
                        ans+=(a)*(a-1);
                       // jum[i][j][k][l]=a-1;
                    }
                }
            }
        }
    }
    int del=0;
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=i;k<=n;k++)
            {
                for(l=j;l<=n;l++)
                {
                    if(jum[i][j][k][l]>=1)
                    {
                        del+=jum[i][j][k][l];
                    }
                }
            }
        }
    }*/
    printf("%d",ans);
}
