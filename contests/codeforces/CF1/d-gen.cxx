#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("in.txt","w",stdout);
    srand(135);
    int i,j,k,n;
    int T=100;
    while(T--)
    {
        n=rand()%3+3;
        printf("\n%d\n",n);
        for(i=1;i<=n;i++)
        {
            printf("%d ",rand()%n+1);
        }

    }
}
