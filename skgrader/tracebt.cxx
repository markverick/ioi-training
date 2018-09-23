#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
char str[100135];
int out[100135];
pair<int,int> sum[100135];
int main()
{
    int n,i,j,k,len;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",str);
        len=strlen(str);
        sum[i].Y=i;
        sum[i].X=0;
        for(j=0;j<len-1;j++)
        {
            if(str[j]=='R')
                sum[i].X=sum[i].X+1;
            else
                sum[i].X=sum[i].X*10-1;
        }
    }
    sort(&sum[1],&sum[n+1]);
    for(i=1;i<=n;i++)
        out[sum[i].Y]=i;
    for(i=1;i<=n;i++)
        printf("%d\n",out[i]);
}
