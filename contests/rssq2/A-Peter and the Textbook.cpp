#include<bits/stdc++.h>
using namespace std;
char ch[3];
int hsh[135];
int main()
{
    int i,j,k,T,n,q,a;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&q);
        for(i=1;i<=n;i++)
        {
            hsh[i]=1;
        }
        while(q--)
        {
            scanf("%s %d",ch,&a);
            if(ch[0]=='-')
            {
                hsh[a]=0;hsh[n-a+1]=0;
            }
            else
            {
                j=0;
                for(i=1;i<=n;i++)
                {
                   if(hsh[i]==1)
                        j++;
                   if(j==a)
                   {
                       printf("%d\n",i);
                       break;
                   }
                }
            }
        }
    }
}
