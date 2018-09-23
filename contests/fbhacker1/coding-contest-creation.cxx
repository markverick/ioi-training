#include<bits/stdc++.h>
using namespace std;
int a[100135];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,n,i,j,k,t,num=1,sum=0;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        num=1;sum=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
//        a[n+1]=-1;
        for(i=1;i<n;i++)
        {
            if(a[i+1]-a[i]>0)
            {
                if(a[i+1]-a[i]<=10*(4-num) )
                {
                    num+=(a[i+1]-a[i]-1)/10+1;
                    sum+=(a[i+1]-a[i]-1)/10;
                    while(num>4)
                    {
                        printf("FAILED\n");
                        num-=4;
                    }
                }
                else
                {
                    sum+=4-num;
                    num=1;
                }
            }
            else
            {
                sum+=4-num;
                num=1;
            }
        }
        sum+=4-num;
        printf("Case #%d: %d\n",t,sum);
    }
}
