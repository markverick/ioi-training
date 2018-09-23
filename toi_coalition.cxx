#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int a[300135];
pair<int,int> b[300135];
int qs[300135];
int to[300135];
int main()
{
    int n,i,j,sum=0,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]={-a[i],i};
        sum+=a[i];
    }
    sort(&b[1],&b[n+1]);
    for(i=1;i<=n;i++)
    {
        to[b[i].Y]=i;
    }
    for(i=1;i<=n;i++)
    {
        qs[i]=qs[i-1]-b[i].X;
    }
    int hs=0;
    for(i=1;i<=n;i++)
    {
        if(qs[i]>sum/2)
        {
            hs=qs[i-1];
            break;
        }
    }
    x=upper_bound(&qs[1],&qs[n+1],(double)sum/2)-&qs[1]+1;
    //printf("X = %d\n",x);
    int y;
    for(i=1;i<=n;i++)
    {
        if(to[i]<=x)
        {
            /*y=qs[x]-a[i];j=0;
            while(y<sum/2)
            {
                j++;
                y+=-b[x+j].X;
            }*/
            printf("%d\n",x-1);
        }
        else
        {
            y=qs[x]+a[i];j=0;
            for(j=x;j>=1;j--)
            {
                if(y+b[j].X>sum/2)
                {
                    y+=b[j].X;
                }
                else
                    break;
    //            y-=-b[x-j].X;
  //              j++;
            }
            printf("%d\n",j);
        }
    }
}
