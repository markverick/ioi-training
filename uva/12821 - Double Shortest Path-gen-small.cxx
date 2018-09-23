#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","w",stdout);
    srand(3434);
    int T=4000,t=1;
    while(T--)
    {
        int n=rand()%13+1,m=rand()%30+3,i,j,k;
        printf("%d %d\n",n,m);
        printf("%d %d %d %d\n",1,rand()%n+1,rand()%10+1,rand()%11);
        printf("%d %d %d %d\n",rand()%n+1,n,rand()%10+1,rand()%11);
        for(i=3;i<=m;i++)
        {
            printf("%d %d %d %d\n",rand()%n+1,rand()%n+1,rand()%1000+1,rand()%1001);
        }
        t++;
    }


}
