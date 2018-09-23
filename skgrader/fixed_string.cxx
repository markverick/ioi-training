#include<bits/stdc++.h>
using namespace std;

char maps[135][135];
vector<char> small[135];
int peated[135][135];
int len[135];
int med[135];
int main()
{
    int T,i,j,k,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",maps[i]);
            len[i]=strlen(maps[i]);
        }
        bool fu=1;
        for(i=0;i<n;i++)
        {
            small[i].emplace_back(maps[i][0]);
            for(j=1;j<len[i];j++)
            {
                if(maps[i][j]!=maps[i][j-1])
                    small[i].emplace_back(maps[i][j]);
            }/*
            for(j=0;j<small[i].size();j++)
            {

                printf("%c ",small[i][j]);
            }
            cout << "\n";*/
        }
        for(i=1;i<n;i++)
        {
            if(small[i].size()!=small[i-1].size())
            {
                fu=0;break;
            }
        }
        if(fu==1)
        for(i=1;i<n;i++)
        {
            for(j=0;j<small[i].size();j++)
            {
                if(small[i][j]!=small[i-1][j])
                {
                    fu=0;break;
                }
            }
            if(fu==0)
                break;
        }
        if(fu==0)
        {
            printf("NO\n");
            for(i=0;i<n;i++)
            {
                small[i].clear();
            }
            memset(peated,0,sizeof peated);
        memset(med,0,sizeof med);
            continue;
        }
        for(i=0;i<n;i++)
        {
            int idx=0;
            peated[i][0]++;
            for(j=1;j<len[i];j++)
            {
                if(maps[i][j]!=maps[i][j-1])
                {
                    idx++;
                    peated[i][idx]++;
                }
                else
                {
                    peated[i][idx]++;
                }
            }
            /*for(j=0;j<small[0].size();j++)
            {
                printf("%d ",peated[i][j]);
            }
            cout << "\n";*/
        }
        int xbar;
        int cot=0;
        for(i=0;i<small[0].size();i++)
        {
            for(j=0;j<n;j++)
            {
                med[j]=peated[j][i];
            }
            sort(&med[0],&med[n]);
            xbar=med[n/2];
            //xbar=round(double(sum)/n);
            for(j=0;j<n;j++)
            {
                cot+=abs(xbar-peated[j][i]);
            }
        }
        printf("%d\n",cot);
        for(i=0;i<n;i++)
        {
            small[i].clear();
        }
        memset(peated,0,sizeof peated);
        memset(med,0,sizeof med);
    }
}
