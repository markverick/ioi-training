#include<bits/stdc++.h>
int n;
unsigned long long fib[10000];

unsigned long long fx(int x)
{
    if(fib[x]>0)
    {
        return fib[x];
    }
    if (x==1)
    {
        return 1;
    }
    if(x==0)
    {
        return 1;
    }
    return fib[x]= fx(x-1)+fx(x-2);
}

int main()
{
    fib[0]=1;
    fib[1]=1;
    unsigned long long cot=0;
    int m;
    scanf("%d",&m);
    int i,j,k;
    for(i=0;i<m;i++){
        scanf("%d",&n);
        if(n!=0){
            cot=fx(n);
            printf("%llu\n",cot);
        }
        else{
            printf("0\n");
        }


    }

}
