#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int a[100135];
pair<int,int> b[100135];

int main()
{
    int c,n,i,j,k,m,sum=0;
    scanf("%d %d",&c,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        //sum+=a[i];
    }
    sort(&a[1],&a[n+1]);
    j=0;
    for(i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])
        {
            j++;
            b[j].X=a[i];
            b[j].Y++;
        }
        else
        {
            b[j].Y++;
        }
    }
    m=j;
    for(i=1;i<=m;i++)
    {
//        b[i].X=b[i].X-b[i-1].X;
        printf("%d %d\n",b[i].X,b[i].Y);
    }
    for(i=m;i>=1;i--)
    {
        printf("%d\n",c);
        if(c-( (b[i].X-b[i-1].X)*b[i].Y)>=0)
        {
            c-=(b[i].X-b[i-1].X)*b[i].Y;
            b[i-1].Y+=b[i].Y;
            b[i].Y=0;
        }
        else
        {
            b[i-1].Y+=c%b[i].X;
            b[b[i].X-c/b[i].Y];
        }
    }
    for(i=1;i<=m;i++)
    {
        sum+=(b[i].X*b[i].Y)*(b[i].X*b[i].Y);
    }
    printf("%d",sum);
}
