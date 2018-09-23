#include<bits/stdc++.h>
using namespace std;
int a[135],b[135][50];
int even[135],odd[135];
int main()
{
    int i,j,k,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            for(j=1;j<=a[i];j++)
            {
                scanf("%d",&b[i][j]);
            }
            sort(&b[i][1],&b[i][a[i]+1]);
            if(b[i][1]%2)
                odd++;
            for(j=2;j<=a[i];j++)
            {
                if(b[i][j]%2&&b[i][j-1])
            }
        }
    }
}
