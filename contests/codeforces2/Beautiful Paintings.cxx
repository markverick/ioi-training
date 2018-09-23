#include<bits/stdc++.h>
using namespace std;
int a[1135],hsh[1135];
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        hsh[a[i]]++;
    }
    int fu=0,cot=0;
    for(j=1;j<=1000;j++)
    {
        fu=0;
        for(i=1;i<=1000;i++)
        {
            if(hsh[i]>0)
            {
                if(fu==1)
                    cot++;
                fu=1;
                hsh[i]--;
            }
        }
    }
    printf("%d\n",cot);
}
