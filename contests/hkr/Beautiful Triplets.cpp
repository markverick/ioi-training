#include<bits/stdc++.h>
using namespace std;
int hsh[50135];
int main()
{
    int i,j,k,n,d,a;
    scanf("%d %d",&n,&d);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        hsh[a]=1;
    }
    int cot=0;
    for(i=0;i<=20000;i++)
    {
        if(hsh[i]==1&&hsh[i+d]==1&&hsh[i+2*d]==1)
            cot++;
    }
    printf("%d",cot);
}
