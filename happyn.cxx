#include<bits/stdc++.h>
using namespace std;
int hsh[1135];
char str[15];
int main()
{
    int T,i,j,k,n,sum=0;;
    scanf("%d",&T);
    while(T--)
    {
        memset(hsh,0,sizeof hsh);
        scanf("%d",&n);
        while(true)
        {
            sum=0;
            while(n>0)
            {
                sum+=(n%10)*(n%10);
                n/=10;
            }
            n=sum;
            //printf("%d\n",sum);
            if(hsh[n]==1)
                break;
            hsh[n]=1;
        }
        if(hsh[1]==1)
            printf("Happy\n");
        else
            printf("Unhappy\n");
    }
}
