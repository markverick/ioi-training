#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T=10,i,j,k,n;
    srand(135);
    freopen("in.txt","w",stdout);
    printf("%d\n",T);
    while(T--)
    {
        n=4;
        printf("%d\n",n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                printf("%d ",rand()%10);
            }
            printf("\n");
        }
    }
}
