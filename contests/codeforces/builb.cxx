#include<bits/stdc++.h>
using namespace std;
int hsh[135];
int main()
{
    int i,j,n,m,a,b,cot=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        for(j=1;j<=a;j++)
        {
            scanf("%d",&b);
            hsh[b]=1;
        }
    }
    for(i=1;i<=m;i++)
    {
        if(hsh[i]==1)
            cot++;
    }
    if(cot==m)
        printf("YES");
    else
        printf("NO");
}
