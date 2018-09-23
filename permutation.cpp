#include<bits/stdc++.h>
int result[10000];
int check[10000];
int n;
void dp(int idx)
{
    int i;
    if(idx==n)
    {
        for(i=0;i<n;i++)
        {
            printf("%d",result[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(check[i])
                continue;

            result[idx]=i;
            check[i]=1;
            dp(idx+1);
            check[i]=0;
        }
    }
}
int main()
{
    int i;
    scanf("%d",&n);
    dp(0);
}
