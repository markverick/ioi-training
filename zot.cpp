#include<bits/stdc++.h>

int main()
{
    int n;
    scanf("%d",&n);
    int i,j,k;
    int a,cot=0,hi=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        if(a==0)
            cot=0;
            else
                cot++;
        if(cot>hi)hi=cot;
    }
    printf("%d",hi);
}
