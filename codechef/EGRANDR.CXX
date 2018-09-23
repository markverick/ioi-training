#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,i,j,k,a,n,bc,sum,fk,haha=0;
    scanf("%d",&T);
    while(T--)
    {
        fk=0;bc=0;haha=0;sum=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            if(a<=2||a>5)
                fk=1;
            if(a==5)
                bc=1;
            sum+=a;
        }
        if((double)sum/n>=3.99999)
            haha=1;
        if(fk==0&&bc==1&&haha==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
