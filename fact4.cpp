#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    int two=n/5+n/25+n/125+n/625+n/3125,prod=1;
    for(i=2;i<=n;i++)
    {
        if(i%5==0)
        {
            j=i;
            while(j%5==0)
            {
                j/=5;
            }
            prod*=j;
            prod%=10;
        }
        else if(i%2==0&&two>0)
        {
            prod*=i/2;
            prod%=10;
            two--;
        }
        else
        {
            prod*=i;
            prod%=10;
        }
    }
    printf("%d",prod);
}
