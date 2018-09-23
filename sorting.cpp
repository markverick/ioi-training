#include<stdio.h>

bool hsh[10000000];
int main()
{
    int n=0;
    int a;
    while(scanf("%d",&a)!=EOF){
        hsh[a]++;n++;
    }
    int i,j,k;
    int cot=0;
    for(i=0;cot<n;i++)
    {
        for(j=0;j<hsh[i];j++)
        {
            printf("%d\n",i);
            cot++;
        }
    }
}
