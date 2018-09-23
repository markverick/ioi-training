#include<bits/stdc++.h>
using namespace std;
long long a[10135];
int main()
{
    long long T,i,j,k,n,e,m,b,score=0;
    scanf("%lld",&T);
    while(T--)
    {
        memset(a,0,sizeof a);
        scanf("%lld %lld %lld %lld",&n,&k,&e,&m);
        for(i=1;i<n;i++)
        {
            for(j=1;j<=e;j++)
            {
                scanf("%lld",&b);
                a[i]+=b;
            }
        }
        score=0;
        for(i=1;i<e;i++)
        {
            scanf("%lld",&b);
            score+=b;
        }
        sort(&a[1],&a[n]);
        a[n]=1000000000000000000;
        a[n+1]=1000000000000000001;
        b=-1;
        for(i=n-k;i<n;i++)
        {
//            printf("%lld\n",i);
            if(a[i]!=a[i+1])
            {
                b=a[i]+1;
                break;
            }
        }
//        printf("%lld\n",b);
        b=b-score;
//        printf("%lld %lld %lld\n",b,score,a[1]);
        if(b>m)
        {
            printf("Impossible\n");
        }
        else if(b<=0)
        {
            printf("0\n");
        }
        else
        {
            printf("%lld\n",b);
        }
    }
}
