#include<bits/stdc++.h>
using namespace std;
int a[13500];
int main()
{
    int T,n,m,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(&a[0],&a[n]);
        int cot=1;
        for(i=1;i<n;i++)
        {
            if(a[i]!=a[i-1])
            {
                cot++;
            }
        }
        if(cot==m)
        {
            printf("ok\n");
        }
        else if(cot>m)
        {
            printf("wow\n");
        }
        else
        {
            printf("orz\n");
        }
    }
}
