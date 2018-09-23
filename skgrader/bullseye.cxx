#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,i,j,k;
    long long r,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld %lld",&r,&n);
        long long mid,fst=0,lst=1000000135,mc=0;
        while(fst<=lst)
        {
            mid=(fst+lst)/2;
            //printf("%lld %lld %lld\n",fst,mid,lst);
            //printf("=%lld\n",2*r*mid-3*mid+2*mid*(mid+1));
            //system("pause");
            if(-3+2*(mid+1)<=(double)n/mid-2*r)
            {
                mc=max(mc,mid);
                fst=mid+1;
            }
            else
            {
                lst=mid-1;
            }
        }
        printf("%lld\n",mc);
    }
}
