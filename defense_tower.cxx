#include<bits/stdc++.h>
using namespace std;
int n;
int a[60];
int b[60];
map<unsigned long long,int> jum[60];
int dp(int idx,unsigned long long bit)
{
    if(jum[idx][bit]>0)
    {
        return jum[idx][bit];
    }
    if(idx<=0)
    {
        return 0;
    }
    int mc=0;
    int i,j;
    for(i=n;i>=1;i--)
    {
        //printf("%d\n",(1<<(i-1)));
        if(bit==(bit|(1<<(i-1))))
            continue;
        //printf("2=%d\n",bit);
        if(a[i]>b[idx])
        {
            mc=max(mc,dp(idx-1,bit|(1<<(i-1)))+a[i]);
        }
        else
        {
            for(j=1;j<=n;j++)
            {
                if(a[j]>b[idx])
                    break;
                if(bit==(bit|(1<<(j-1))))
                    continue;
                    mc=max(mc,dp(idx-1,bit|(1<<(j-1))));
                break;

            }
        }
        break;
    }
    return jum[idx][bit]=mc;
}
int main()
{
    int i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<=n;i++)
            jum[i].clear();

        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
        }
        sort(&a[1],&a[n+1]);
        sort(&b[1],&b[n+1]);
        /*for(i=0;i<20;i++)
        {
            cout << tmp[i];
        }*/
        printf("%d\n",dp(n,(unsigned long long)0));
    }
}
