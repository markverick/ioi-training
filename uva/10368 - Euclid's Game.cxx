#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,c;
    while(scanf("%lld %lld",&a,&b)!=EOF)
    {
        if(a==0&&b==0)
            return 0;
        c=0;
        if(a>b)
            swap(a,b);
        while(a*2>b)
        {
            b=b-a;
            if(a>b)
                swap(a,b);
            if(a>0)
                c++;
        }
        if(c%2==0)
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }
}
