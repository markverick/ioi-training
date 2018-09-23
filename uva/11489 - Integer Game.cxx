#include<bits/stdc++.h>
using namespace std;
char s[1135];
int main()
{
    int T,t,len,n,i,sum,tri=0,fu=0;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        tri=0;sum=0;fu=0;
        scanf("%s",s+1);
        len=strlen(s+1);
        for(i=1;i<=len;i++)
        {
            sum+=s[i]-'0';
            if((s[i]-'0')%3==0)
                tri++;
        }
        printf("Case %d: ",t);
        if(sum%3==0)
        {
            if(tri%2==0)
                printf("T\n");
            else
                printf("S\n");
        }
        else
        {
            for(i=1;i<=len;i++)
            {
                if(sum%3==(s[i]-'0')%3)
                {
                    if(tri%2==0)
                        fu=1;
                }
            }
            if(fu==0)
                printf("T\n");
            else
                printf("S\n");
        }
    }
}
