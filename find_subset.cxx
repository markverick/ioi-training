#include<bits/stdc++.h>
using namespace std;
int a[220];
int main()
{
    int T,n,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int mc=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            mc=max(mc,a[i]);
        }
        int x=1,sum;
        //printf("%d\n",sum-1);
        int fu=0;
        while(true)
        {
            sum=1<<31;
            sum--;
            //printf("=%d\n",sum);
            if(x>sum||x>mc*2)
                break;
            for(i=0;i<n;i++)
            {
                if((x|a[i])==a[i])
                    sum&=a[i];
                //printf("sum=%d\n",sum);
            }
            if(sum==x)
            {
                printf("YES\n");fu=1;
                break;
            }
            x=x<<1;
        }
        if(fu==0)
            printf("NO\n");
    }
}
