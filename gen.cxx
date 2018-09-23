#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("out.txt","w",stdout);
    srand(999);
    int T=1000,i,j,k;
    while(T--)
    {
        int r=rand()%10+1,c=rand()%10+1,d=rand()%10+1,n=4;
        printf("%d %d %d %d\n",r,c,n,d);
        for(i=1;i<=n;i++)
        {
            printf("%d %d\n",rand()%r+1,rand()%c+1);
        }
    }
    printf("0 0 0 0\n");

}
