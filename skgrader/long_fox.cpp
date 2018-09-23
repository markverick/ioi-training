#include<bits/stdc++.h>
using namespace std;
int a[1200];
int b[1200];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    b[0]=1;
    int hi=1;
    for(i=0;i<n;i++)
    {
        int cot=0;
        int ma=0;
        for(j=i;j>=0;j--)
        {
            if(a[i]>a[j])
            {
                ma=max(ma,b[j]+1);
            }
        }
        b[i]=ma;
        hi=max(hi,ma);

    }
    printf("%d",hi+1);
}
