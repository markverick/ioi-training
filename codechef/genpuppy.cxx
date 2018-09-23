#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
    int n,m,i,j,k,T=10;
    srand(135);
    printf("%d\n",T);
    while(T--)
    {
        n=rand()%4+1;
        m=rand()%(n*n)+1;
        printf("%d %d\n",n,m);
        for(i=1;i<=m;i++)
        {
            printf("%d %d\n",rand()%n+1,rand()%n+1);
        }
    }
}
