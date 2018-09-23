#include<bits/stdc++.h>
using namespace std;
char a[1135],b[1135],c[1135],d[1135];
int la,lb,lc;
int tod[1135][1135];
vector<int> v,u;
int main()
{
    int i,j,k;
    scanf("%s %s %s",a,b,c);
    la=strlen(a);
    lb=strlen(b);
    lc=strlen(c);
    for(i=0;i<lc;i++)
    {
        u.emplace_back(c[i]-'0');
    }
    for(i=lb-1;i>=0;i--)
    {
        for(j=la-1;j>=0;j--)
        {
            tod[i][j+1]+=(a[j]-'0')*(b[i]-'0');
            if(tod[i][j+1]>9)
            {
                tod[i][j]+=tod[i][j+1]/10;
                tod[i][j+1]%=10;
            }
        }
    }
    for(i=lb-1;i>=0;i--)
    {
        for(j=la;j>=0;j--)
        {
            d[j+i]+=tod[i][j];
        }
    }
    for(i=lb+la-1;i>=0;i--)
    {
        if(d[i]>9)
        {
            d[i-1]+=d[i]/10;
            d[i]%=10;
        }
    }
    int fu=0;
    for(i=0;i<la+lb;i++)
    {
        if(d[i]!=0)
            fu=1;
        if(fu==1)
            v.emplace_back(d[i]);
    }
    if(v==u)
        printf("truth");
    else
        printf("dream");
}
