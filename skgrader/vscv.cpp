#include<bits/stdc++.h>
int n,m,p[13000];
int main()
{
    int t,i,j,k;
    scanf("%d",&t);
    for(i=1;i<10000;i++)
    {
        if(i%2==0||i%3==0||i%4==0||i%5==0||i%6==0||i%7==0||i%8==0||i%9==0)
        {
            i++;
        }
        else
        {
            p[i]=1;
        }
    }
    int cot=0;
    for(i=0;i<t;i++)
    {
        cot=0;
        scanf("%d",&n);
        for(j=2;j<=n;j++)
        {
            for(k=2;k<n;k++)
            {
                if(p[j]==0&&p[k]==0)
                {
                    if(n==j+2*k)
                    {
                        cot++;
                    }
                }
            }
        }
        printf("%d\n",cot);
    }

}
