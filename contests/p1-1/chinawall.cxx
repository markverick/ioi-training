#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","w",stdout);
    srand(135);
    int n,i,j,k,T=100;
    while(T--)
    {
        n=rand()%10+1;
        printf("%d\n",n);
        for(i=1;i<=5;i++)
        {
            if(rand()%2)
                printf("%d",rand()%10);
            else
                printf("@");
            for(j=2;j<=n;j++)
            {
                printf("%d",rand()%10);
            }
            printf("\n");
        }
    }
}
