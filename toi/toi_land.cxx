#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,a,b,c,d,mc=0;
    scanf("%d %d %d %d %d %d",&x,&y,&a,&b,&c,&d);
    if(a+c>x&&b+d>y)
    {
        printf("%d",max((x-c)*(y-b),(y-d)*(x-a)) );
    }
    else
    {
        if(a+c<x)
            mc=max(mc,y*(x-a-c));
        if(b+d<y)
            mc=max(mc,x*(y-b-d));
        mc=max(mc,(x-c)*(y-b));
        mc=max(mc,(y-d)*(x-a));
        printf("%d",mc);
    }
}
