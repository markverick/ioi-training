#include<bits/stdc++.h>
using namespace std;
int a[12],b[12];
int main()
{
    int i,j,k,T,fk=0,cot,n,m;
    scanf("%d",&T);
    while(T--)
    {
        fk=0;
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
            if(a[i]>b[i])
                swap(a[i],b[i]);
        }
        if(m<2)
            printf("YES\n");
        else if(m>2)
            printf("NO\n");
        else
        {
            if(a[1]==b[2]||a[1]==a[2]||b[1]==a[2]||b[1]==b[2])
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}
