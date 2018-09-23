#include<bits/stdc++.h>
using namespace std;
int n;
char a[60000][250];
int x[60000];
int sum=0;
int main()
{
    int T,t,i,j,k;
    for(i=0;i<101;i++)
        a[0][i]='x';
    sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
        sum+=x[i];
    }
    int idx=0;
    for(i=0;i<n;i++)
    {
        idx++;
        for(j=51000;j>=0;j--)
        {
            for(k=i;k<n;k++)
            {
                if(a[j][k]=='x')
                {
                    a[j+x[i]][k]='x';
                }
            }

        }
    }
    int lo=sum+1;
    for(i=0;i<=sum;i++)
    {
        if(a[i][n/2]=='x'&&abs(sum-i-i)<lo)
        {
            lo=abs(sum-i-i);
        }
    }
    printf("%d\n",lo);
}
