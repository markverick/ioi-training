#include<bits/stdc++.h>
char str[10];
int row[320000],cr[320000];
int col[320000],cc[320000];
int main()
{
    int n,c,a,b,hi=0,i,j,hi2=0;
    scanf("%d %d",&n,&c);
    for(i=0;i<c;i++)
    {
        memset(str,0,sizeof str);
        scanf("%s",str);
        scanf("%d %d",&a,&b);
        if(str[0]=='R')
        {
            row[a]+=b;
            cr[a]=1;
        }
        if(str[0]=='C')
        {
            col[a]+=b;
            cc[a]=1;
        }
        //printf("F");

    }
    for(i=0;i<n;i++)
    {
        if(row[i]>hi)
            hi=row[i];
    }
    for(i=0;i<n;i++)
    {
        if(hi2<hi+col[i])
            hi2=hi+col[i];
    }
    printf("%d",hi2);
}
