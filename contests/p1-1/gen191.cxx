#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,a,b,c,d;
    srand(139);
    printf("100\n");
    for(i=1;i<=100;i++)
    {
        for(j=1;j<=4;j++)
        {
            printf("%d ",rand()%20);
        }
        a=rand()%10;
        b=rand()%10;
        printf("%d %d %d %d",a,b+rand()%10+1,a+rand()%10+1,b);
        printf("\n");
    }
}
