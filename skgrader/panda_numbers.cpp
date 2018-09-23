#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;
char str[120000];
int hsh[12];
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        memset(hsh,0,sizeof hsh);
        vector<int> dig;
        scanf("%s",str);
        sscanf(str,"%d",&n);
        if(n==0)
        {
            printf("Yes\n");
            continue;
        }
        int mn=99;
        int len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(str[i]=='0')
                continue;

            if(hsh[str[i]-'0']==0)
            {
                hsh[str[i]-'0']=1;
                dig.push_back(str[i]-'0');
            }
        }
        sort(dig.begin(),dig.end());
        for(i=0;i<dig.size();i++)
        {
            dig[i]*=dig[i];
        }
        if(n-dig[0]>=0&&n%dig[0]<=9)
        {
            printf("Yes\n");
        }
        else
        {
            n-=dig[0]*(n/dig[0])+dig[0];
            if(n-dig[1]>=0&&n%dig[1]<=9)
            {
                printf("Yes\n");
            }
            else
            printf("No\n");
        }
    }
}


