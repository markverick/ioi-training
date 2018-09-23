#include<bits/stdc++.h>
using namespace std;

int n,x[22],y[22];
int dp(int bit,vector<pair<int,int> > lst)
{
    if(__builtin_popcount(bit)==n*2)
    {
        return 0;
    }
    int mn=1000000000,i,j,k;
    for(i=1;i<=n*2;i++)
    {
        if(((1<<(i-1))|bit)==bit)
            continue;
        for(j=1;j<=n*2;j++)
        {
            if(((1<<(j-1))|bit)==bit)
                continue;
            for(k=0;k<lst.size();k++)
            {

            }
        }
    }
}
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n*2;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
}
