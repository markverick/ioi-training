#include<stdio.h>
char name[20][20];
char bl[20],wt[20];
int main()
{
    int i,j,k,u,l,r,d,m,n;
    scanf("%d %d %d %d %d %d",&n,&m,&u,&l,&r,&d);
    for(i=0;i<n;i++)
    {
        scanf("%s",name[i]);
    }
    for(i=0;i<r+l+m;i++)
    {
        if(i%2==0)
        {
            bl[i]='#';
            wt[i]='.';
        }
        if(i%2==1)
        {
            bl[i]='.';
            wt[i]='#';
        }
    }
    for(i=0;i<u;i++)
    {
        if(i%2==0)
            printf("%s",bl);
        else
            printf("%s",wt);
        printf("\n");
    }
    for(i=u;i<u+n;i++)
    {
        for(j=0;j<l;j++)
        {
            i%2==0?printf("%c",bl[j]):printf("%c",wt[j]);
        }
        printf("%s",name[i-u]);
        for(j=l+m;j<l+m+r;j++)
        {
            i%2==0?printf("%c",bl[j]):printf("%c",wt[j]);
        }
        printf("\n");
    }
    for(i=u+n;i<u+n+d;i++)
    {
        if(i%2==0)
            printf("%s",bl);
        else
            printf("%s",wt);
        printf("\n");
    }
}
