#include<bits/stdc++.h>
int val=0;
int main()
{
    //freopen("output.txt","w",stdout);
    int t,i,j,k,hi,xx,cot=0;
    int n;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        xx=-1;
        hi=0;cot=0;val=0;
        scanf("%d",&n);
        for(i=0;i<=n;i++)
        {
            if(i!=n)
                scanf("%d",&val);
            if(val==0&&i!=n)
            {
                cot++;
            }
            else
            {
                if(cot%2==1)
                {
                    if(cot>hi)
                    {
                        hi=cot;
                        xx=i-cot/2;
                    }

                }
                cot=0;
            }

        }
        if(xx==-1)
            printf("-1\n");
        else
            printf("%d\n",xx-1);

    }
}
