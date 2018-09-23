#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
pair<int,int> x[555],y[555];
int main()
{
	int i,j,k,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x[i].X,&y[i].X);
        x[i].Y=i;y[i].Y=i;
    }
    sort(&x[1],&x[n+1]);
    sort(&y[1],&y[n+1]);
    int cot=0;
    for(i=1;i<=n;i++)
        if(x[i].X!=i)cot+=abs(x[i].X-i);
    for(i=1;i<=n;i++)
        if(y[i].X!=i)cot+=abs(y[i].X-i);
    printf("%d\n",cot);
    for(i=1;i<=n;i++)
    {
        while(x[i].X>i)
        {
            printf("%d U\n",x[i].Y);
            x[i].X--;
        }
    }
    for(i=n;i>=1;i--)
    {
        while(x[i].X<i)
        {
            printf("%d D\n",x[i].Y);
            x[i].X++;
        }
    }
    for(i=1;i<=n;i++)
    {
        while(y[i].X>i)
        {
            printf("%d L\n",y[i].Y);
            y[i].X--;
        }
    }
    for(i=n;i>=1;i--)
    {
        while(y[i].X<i)
        {
            printf("%d R\n",y[i].Y);
            y[i].X++;
        }
    }
}
