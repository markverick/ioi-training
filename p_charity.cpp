#include<bits/stdc++.h>
int n;
char str[10000];
int s[10000];
int e[10000];
int p[10000];
int main()
{
    int i,j,k,t,T;
    int n=0;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        scanf("%s",str);
        for(i=0;strlen(str)!=0;i++)
        {
            sscanf(str,"%d,%d,%d;%s",&s[i],&e[i],&p[i],str);
            printf("%s",str);
        }
        n=i;
        for(i=0;i<=n;i++)
        {
            printf("%d %d %d\n",s[i],e[i],p[i]);
        }
    }
}
