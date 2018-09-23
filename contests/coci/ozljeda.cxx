#include<bits/stdc++.h>
using namespace std;
///LONG LONG LONG LONG!!!
long long a[100135],qs[100135];
int main()
{
    long long i,j,k,all=0;
    scanf("%lld",&k);
    for(i=1;i<=k;i++)
    {
        scanf("%lld",&a[i]);
        qs[i]=qs[i-1]^a[i];
        all^=a[i];
    }
//    qs[0]=all;
    long long Q,L,R;
    scanf("%lld",&Q);
    while(Q--)
    {
        scanf("%lld %lld",&L,&R);
        if(L/(k+1)==R/(k+1))
        {
            if(R%(k+1)==0&&L%(k+1)==0)
            {
                printf("%lld\n",all);
            }
            else if(L%(k+1)==0)
            {
                printf("%lld\n",qs[R%(k+1)]^all);
            }
            else
                printf("%lld\n",qs[R%(k+1)]^qs[L%(k+1)-1]);
        }
        else
        {
            if(R%(k+1)==0&&L%(k+1)==0)
            {
                printf("%lld\n",all);
            }
            else if(R%(k+1)==0)
            {
                printf("%lld\n",qs[L%(k+1)-1]);
            }
            else if(L%(k+1)==0)
            {
                printf("%lld\n",qs[R%(k+1)]^all);
            }
            else
                printf("%lld\n",(qs[L%(k+1)-1])^qs[R%(k+1)]);
        }
    }
}
