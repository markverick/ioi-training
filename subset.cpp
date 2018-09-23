#include<bits/stdc++.h>
using namespace std;
void decToBin(int n)
{
    if (n / 2 != 0)
    {
        decToBin(n / 2);
    }
    printf("%d", n % 2);
}
int main()
{
    int n,x;
    int i,j,k;
    scanf("%d",&n);
    for(i=0; i<pow(2,(double)n); i++)
    {
        if(i!=0)
            x=log2(i);
        else
            x=0;
        //printf("LOG2 = %d ",x);
        for(j=0;j<n-1-x;j++){
            printf("0");
        }
        decToBin(i);
        printf("\n");
    }

}
