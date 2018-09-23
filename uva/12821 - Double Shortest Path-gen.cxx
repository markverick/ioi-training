#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","w",stdout);
    srand(135);
    int T=100,t=1;
    while(T--)
    {
        int n=rand()%500+1,m=rand()%2000+1,i,j,k;
        printf("%d %d\n",n,m);
        for(i=1;i<=m;i++)
        {
            printf("%d %d %d %d\n",rand()%n+1,rand()%n+1,rand()%1000+1,rand()%1001);
        }
        t++;
    }


}
