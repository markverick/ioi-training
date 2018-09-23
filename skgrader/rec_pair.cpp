#include<bits/stdc++.h>
#define MP make_pair
using namespace std;
int mat[55][55];
int sum[55][55];
int jum[55][55][55][55];
map<int,int> hsh[55][55];
map<pair<pair<int,int>,pair<int,int> >,bool > ha;
set<int> st[55][55];
set<int> ::iterator it;
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
                    st[i][j].insert(sum[k][l]-sum[k][j-1]-sum[i-1][l]+sum[i-1][j-1]);
                }
            }
            for(k=i;k<=n;k++)
            {
                for(l=j;l>=1;l--)
                {
                    hsh[i][j][sum[k][l]-sum[k][j-1]-sum[i-1][l]+sum[i-1][j-1]]++;
                    st[i][j].insert(sum[k][l]-sum[k][j-1]-sum[i-1][l]+sum[i-1][j-1]);
                }
            }
        }
    }
    int ans=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            //int a=sum[k][l]-sum[k][j-1]-sum[i-1][l]+sum[i-1][j-1];
            for(it=st[i][j].begin();it!=st[i][j].end();it++)
            {
                int b=hsh[i][j][*it];
                if(b>=2)
                ans+=b*(b-1)/2;
            }
        }
    }
    printf("%d",ans);
}
