#include<bits/stdc++.h>
int result[10000];
int check[10000];
int n,m;
int cot=0;
void dp(int idx)
{
    int i,j;
    if(idx==m+1)
    {
        for(i=1;i<=m;i++)
        {
            printf("%d",result[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        for(j=result[idx-1]+1;j<=n;j++)
        {
            if(check[j]==1)
                continue;
            result[idx]=j;
            check[j]=1;
            dp(idx+1);
            check[j]=0;
        }
    }
}
int main()
{
    int i;
    scanf("%d %d",&n,&m);
    dp(1);
}

