#include<bits/stdc++.h>
using namespace std;
int a[1135];
//int qs[1135];
int main()
{
    int T,i,j,k,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int sum=0,cot=1;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1;i<n;i++)
        {
            if(sum+a[i]<a[i+1])
            {
                sum+=a[i];
                cot++;
            }
        }
        printf("%d\n",cot);
    }
}
