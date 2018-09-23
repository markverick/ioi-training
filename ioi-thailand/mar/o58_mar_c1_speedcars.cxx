#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

pair<int,int> p[100135];
int main()
{
    int n,t,i,j,k,a,b;
    scanf("%d %d",&n,&t);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        p[i]=make_pair(a+t*b,a);
    }
    sort(&p[1],&p[n+1]);
    int mn=2000000000,cot=0,mc=0;
    for(i=n;i>=1;i--)
    {
        if(p[i].Y>mn)
        {
            cot++;
        }
        else if(p[i].Y==mn)
        {
            if(p[i].X<mc)
            {
                cot++;
            }
        }
        if(mn>p[i].Y)
        {
            mn=min(mn,p[i].Y);
            mc=p[i].X;
        }
    }
    printf("%d",n-cot);

}
