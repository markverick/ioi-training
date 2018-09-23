#include<bits/stdc++.h>
using namespace std;
char str[1200][1200];
char st[1200][1200];
int cot[1200];
int main()
{
    int n,m;
    int i,j,k,l;
    scanf("%d %d",&n,&m);
    int ll=0;
    for(i=1;i<=n;i++)
    {
        scanf("%s",str[i]);
        ll=strlen(str[i]);
        for(j=0;j<ll;j++)
        {
            if(str[i][j]<'a')
            str[i][j]+=('a'-'A');
        }
    }
    for(i=1;i<=m;i++)
    {
        scanf("%s",st[i]);
        ll=strlen(st[i]);
        for(j=0;j<ll;j++)
        {
            if(st[i][j]<'a')
            st[i][j]+=('a'-'A');
        }
    }
    int le,len,idx;
    for(i=1;i<=m;i++)
    {
        le=strlen(st[i]);
        for(j=1;j<=n;j++)
        {
            len=strlen(str[j]);
            k=0;l=0;
            while(l<len)
            {
                if(str[j][l]==st[i][k])
                {
                    l++;k++;
                }
                else
                {
                    l++;
                }
            }
            //printf("sub[%d] Word[%d] %d == %d\n",i,j,k,le);
            if(k==le)
            {
                cot[j]++;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        printf("%d\n",cot[i]);
    }
}
