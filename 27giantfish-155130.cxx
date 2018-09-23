#include<bits/stdc++.h>
//#define HEAD 2
//#define TAIL 8
#include"fishlib.h"
using namespace std;
/*
int fish_get_L()
{
    int a;
    scanf("%d",&a);
    return a;
}
int fish_check(int x)
{
    if(x>=HEAD&&x<=TAIL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void fish_answer(int x)
{
    if(x==TAIL-HEAD)
    {
        printf("YES");
    }
    else
    {
        printf("NO %d",x);
    }
}*/
int main()
{
    int L,i,j,k;
    L=fish_get_L();
    int fst=0,mid,lst=L,mn=L/2,mc=L/2;
    while(fst<=lst)
    {
        mid=(fst+lst)/2;
        if(fish_check(mid)==1)
        {
            mn=min(mn,mid);
            lst=mid-1;
        }
        else
        {
            fst=mid+1;
        }
    }
    fst=0;lst=L;
    while(fst<=lst)
    {
        mid=(fst+lst)/2;
        if(fish_check(mid)==1)
        {
            mc=max(mc,mid);
            fst=mid+1;
        }
        else
        {
            lst=mid-1;
        }
    }
    //printf("%d %d\n",mc,mn);
    fish_answer(mc-mn+1);
}
