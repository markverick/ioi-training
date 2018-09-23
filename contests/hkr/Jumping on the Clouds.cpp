#include<bits/stdc++.h>
using namespace std;
int a[135];
int main()
{
    int i,j,k,T,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    a[n+1]=1;
    j=1;
    int cot=0;
    while(j<n)
    {
        if(a[j+2]==0)
        {
            cot++;
            j+=2;
        }
        else
        {
            cot++;
            j++;
        }
    }
    printf("%d\n",cot);
}
