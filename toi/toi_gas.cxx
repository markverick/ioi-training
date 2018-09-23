#include<bits/stdc++.h>
using namespace std;

int n,m;
int d[1135];
int qs[1135];

int main()
{
    int i,u;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&d[i]);
        qs[i]=qs[i-1]+d[i];
    }
    int fuel=0;
    for(i=1;i<=n;i++)
    {
       // u=(d[i]+m-1)/m;
        //printf("%d\n",fuel);
        if(fuel>=d[i])
        {
            printf("0\n");fuel-=d[i];
        }
        else
        {
            u=( (d[i]-fuel)+m-1 )/m;
            printf("%d\n",u);
            fuel+=u*m;fuel-=d[i];
        }
    }

}
