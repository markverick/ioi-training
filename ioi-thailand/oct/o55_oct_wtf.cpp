#include<bits/stdc++.h>
using namespace std;
int a;
int i,sum=0;
int main()
{
    int fu=-1;
    for(i=1;i<=5;i++)
    {
        scanf("%d",&a);
        sum*=100;
        sum+=a;
        sum%=1007;
    }
    if(sum>300&&sum<=330)
        fu=0;
    else if(sum>330&&sum<=350)
        fu=1;
    else if(sum>515&&sum<=560)
        fu=0;
    else if(sum>300&&sum<=400)
        fu=0;
    else if(sum<=100)
        fu=0;
    if(fu==0)
        printf("no");
    else if(fu==1)
    printf("yes");
    else
        printf("yes");
}
