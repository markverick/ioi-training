#include<stdio.h>
#include<string.h>
int result[10000];
int check[10000];
int n;
int cot=0;
int chck=0;
int target;
int fac(int n)
{
    if(n!=1)
     return n*fac(n-1);
}
void dp(int idx)
{
    if(chck==1)return;
    int i;
    int j;
    if(idx==n)
    {
        if(cot==target)
        {
            for(i=0;i<n;i++)

            {
                printf("%d",result[i]);
            }
            printf("\n");
            chck=1;
        }

        cot++;
        return;
    }
    else
    {
        for(j=1;j<=n;j++)
        {
            if(check[j])
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
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        if(n!=1)
        {
            target=fac(n)/3;
            dp(0);
            memset(check,0,10000);
            cot=0;
            chck=0;
        }
        else
        {
            printf("1\n");
        }

    }

}
