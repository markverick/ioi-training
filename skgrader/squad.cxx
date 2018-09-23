#include<bits/stdc++.h>
using namespace std;
char temp[120000];
int a[1200];
int main()
{
    int T,i,j,k,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&k);
        int fu=0;

        for(i=0;i<n;i++)
        {
            scanf("%s",temp);
            a[i]=strlen(temp);
        }
        if(n%k!=0)
        {
            printf("Not possible\n");
            continue;
        }
        sort(&a[0],&a[n]);
        for(i=0;i<n/k;i++)
        {
            for(j=i*k+1;j<i*k+k;j++)
            {
                if(a[j]!=a[j-1])
                {
                    fu=1;
                    break;
                }
            }
            if(fu==1)
                break;
        }
        if(fu==0)
        {
            printf("Possible\n");
        }
        else
            printf("Not possible\n");
    }
}
