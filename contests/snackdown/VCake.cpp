#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back
using namespace std;
long long x[6];
int main()
{
    long long T,i,j,k,r,c,R,C,fu;
    scanf("%lld",&T);
    while(T--)
    {
        fu=0;
        scanf("%lld %lld %lld %lld %lld",&r,&c,&x[0],&x[1],&x[2]);
        if(x[0]+x[1]+x[2]!=r*c)
        {
            printf("No\n");
            continue;
        }
        sort(&x[0],&x[3]);
        do
        {
            if(x[0]%r==0)
            {
                C=(c-x[0]/r);R=r;
                if(x[1]%R==0)
                {
                    fu=1;break;
                }
                if(x[1]%C==0)
                {
                    fu=1;break;
                }
            }
            if(x[0]%c==0)
            {
                R=(r-x[0]/c);C=c;
                if(x[1]%R==0)
                {
                    fu=1;break;
                }
                if(x[1]%C==0)
                {
                    fu=1;break;
                }
            }
        }
        while(next_permutation(&x[0],&x[3]));
        if(fu==0)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }
}
