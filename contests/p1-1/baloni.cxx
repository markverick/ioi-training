#include<bits/stdc++.h>
using namespace std;
int hsh[1000135];
int main()
{
    int n,i,j,k,a,cot=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(hsh[a+1]==0)
            cot++;
        else
            hsh[a+1]--;
        hsh[a]++;
    }
    printf("%d",cot);
}
