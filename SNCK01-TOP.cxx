#include<bits/stdc++.h>
using namespace std;
int a[55][55];
int main()
{
    int t,n,m,i,j,res,ze,now;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        res=0;
        for(i=0;i<n;i++)
        {
            ze=0;
            for(j=m-1;j>=0;j--)
            {
                now=a[i][j]-1;
                if(now>=ze)
                    now++;
                ze=now;
            }
            res^=now;
        }
        if(res) printf("FIRST\n");
        else printf("SECOND\n");
    }
}
