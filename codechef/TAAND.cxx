#include<bits/stdc++.h>
using namespace std;
int bit[33][300135];
int hsh[300135];
int val[300135];
int main()
{
    int i,j,k,n,a;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&val[i]);
        a=val[i];
        j=0;
        while(a>0)
        {
            bit[j++][i]=a%2;
            a/=2;
        }
    }
    int cot=0;
    for(i=32;i>=0;i--)
    {
        cot=0;
        for(j=1;j<=n;j++)
        {
            if(hsh[j]==0&&bit[i][j]==1)
                cot++;
        }
        if(cot>=2)
        {
            for(j=1;j<=n;j++)
            {
                if(hsh[j]==0&&bit[i][j]==0)
                {
                    hsh[j]=1;
                }
            }
        }
    }
    vector<int> v;
    for(i=1;i<=n;i++)
    {
        if(hsh[i]==0)v.emplace_back(val[i]);
    }
    if(v.size()<2)
        printf("0");
    else
        printf("%d",v[0]&v[1]);
}
