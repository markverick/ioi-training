#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int y[1135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,mn=MI,x,sum,cot,a,b,mc=0;
	scanf("%d %d %d",&n,&a,&b);
	for(i=1;i<=n;i++)
        scanf("%d",&y[i]),mc=max(mc,y[i]);
    for(i=max(mc,a);i<=b;i++)
    {
        sum=0;cot=0;
        for(j=1;j<=n;j++)
        {
            if(sum+y[j]>i)
            {
                cot+=i-sum;
                sum=y[j];
            }
            else
                sum+=y[j];
        }
        cot+=i-sum;
        if(cot<mn)
            mn=cot,x=i;
    }
    printf("%d",x);
}
