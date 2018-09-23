#include<bits/stdc++.h>
using namespace std;

int main()
{
    srand(135);
    freopen("in.txt","w",stdout);
    int i,j,k,n=10,q=100;
    printf("%d\n",n);
    printf("%d %d\n",rand()%10+1,0);
    for(i=2;i<=n;i++)
    {
        printf("%d %d\n",rand()%10+1,rand()%i);
    }
    printf("%d\n",q);
    while(q--)
    {
        if(rand()%2)
        {
            printf("1 %d %d\n",rand()%(n+1),rand()%6+1);
        }
        else
        {
            printf("2 %d\n",rand()%(n+1));
        }
    }
}
