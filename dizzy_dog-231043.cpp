#include<stdio.h>
int tab[55][3];
int walk(int n,int pat)
{
    if(n==1)
        return 1;
    if(tab[n][pat]==0)
    {
        if(pat==0)
            tab[n][pat]=walk(n-1,0)+walk(n-1,1)+walk(n-1,2);
        else if(pat==1)
            tab[n][pat]=walk(n-1,0)+walk(n-1,1);
        else
            tab[n][pat]=walk(n-1,0)+walk(n-1,2);
    }
    return tab[n][pat];
}
int main()
{
    int n;
    scanf("%d",&n);
    if(n==0)
        printf("1");
    else
        printf("%d",walk(n,0)+walk(n,1)+walk(n,2));
    scanf(" ");
}

