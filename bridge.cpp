#include<bits/stdc++.h>
using namespace std;

int a[5000];
int b[5000];
short dat[3200][3200];
int main()
{
    int n;
    scanf("%d",&n);
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                dat[i][j]=dat[i-1][j-1]+1;
            }
            else
            {
                dat[i][j]=max(dat[i-1][j],dat[i][j-1]);
            }
        }
    }
    printf("%d",dat[n][n]);
}
