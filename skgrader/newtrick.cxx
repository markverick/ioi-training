#include<bits/stdc++.h>
using namespace std;
vector<int> tricks;
int hsh[135][135];
int ha[135];
int a[135];
int main()
{
    int n,m,i,j,k,p,c=0,fu=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        fu=0;
        memset(ha,0,sizeof ha);
        scanf("%d",&p);
        for(j=1;j<=p;j++)
        {
            scanf("%d",&a[j]);
            if(a[j]==1)
            {
                tricks.emplace_back(c++);fu=1;
            }
        }
        if(fu==0)
        {
            for(j=1;j<=p;j++)
            {
                for(k=0;k<tricks.size();k++)
                {
                    if(hsh[a[j]][k]==1)
                        ha[k]=1;
                }
            }
            for(j=0;j<tricks.size();j++)
            {
                if(ha[j]==1)
                {
                    for(k=1;k<=p;k++)
                    {
                        hsh[a[k]][j]=1;
                    }
                }
            }
        }
        else
        {
            for(j=1;j<=p;j++)
            {
                if(a[j]==1)
                    continue;
                hsh[a[j]][tricks.size()-1]=1;
            }
        }
    }
    printf("1\n");
    for(i=2;i<=n;i++)
    {
        int cot=0;
        for(j=0;j<tricks.size();j++)
        {
            if(hsh[i][j]==1)
                cot++;
        }
        if(cot==tricks.size())
        {
            printf("%d\n",i);
        }
    }
}
