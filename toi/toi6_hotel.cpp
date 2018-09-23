#include<bits/stdc++.h>
using namespace std;
int m;
int lo=999999999;
void dp(int ppl,int cost)
{
    if(ppl<=0)
    {
        lo=min(lo,cost);
        return;
    }
    dp(ppl-1,cost+500);
    dp(ppl-2,cost+800);
    dp(ppl-5,cost+1500);
    dp(ppl-15,cost+3000);
}
int main()
{
    int n;
    scanf("%d",&n);
    int price=0;
    while(n-15>=0&&n/15!=0)
    {
        n-=15;
        price+=3000;
    }

    m=n;
    dp(m,0);
    printf("%d",lo+price);

}

/*

while(n-5>15&&n/5!=0)
    {
        n-=5;
        price+=1500;
    }
    while(n-2>15&&n/2!=0)
    {
        n-=2;
        price+=800;
    }
    while(n-1>15)
    {
        n-=1;
        price+=500;
    }

    */
