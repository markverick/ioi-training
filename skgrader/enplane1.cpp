#include<bits/stdc++.h>
using namespace std;

vector<int> c[600];
int main()
{
    int a,b,n,i,j,k,l;
    int mn=99999999;
    scanf("%d %d %d",&a,&b,&n);
    for(i=0;i<n;i++)
    {
        int p,m,fu=0;
        scanf("%d %d",&p,&m);
        for(j=0;j<m;j++)
        {
            int g
            scanf("%d",&g);
            c[i].push_back(g);
        }
    }
    for(i=0;i<n;i++)
    {
        int fu=0;
        for(j=0;j<c[i].size();j++)
        {
            if(fu==0&&c[i][j]==a)
            {
                continue;
                fu=1;
            }
            if(fu==1)
            for(k=0;k<n;k++)
            {
                int fo=0;
                for(l=0;l<c[k].size();l++)
                {

                    if(c[i][j]==c[k][l])
                    {

                    }
                }
            }
        }
    }
}
