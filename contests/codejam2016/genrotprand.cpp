#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","w",stdout);
    srand(135);
    int T=100,i,j,k;
    printf("%d\n",T);
    while(T--)
    {
        for(i=1;i<=100;i++)
        {
            if(rand()%2)
                printf("-");
            else
                printf("+");
        }
        printf("\n");
    }
}
