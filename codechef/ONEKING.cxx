#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n;
pair<int,int> p[100135];
int main()
{
    int i,j,k,T,cot;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&p[i].Y,&p[i].X);
        }
        sort(&p[1],&p[n+1]);
        j=-1;
        cot=0;
        for(i=1;i<=n;i++)
        {
            if(p[i].Y>j)
            {
                cot++;
                j=p[i].X;
            }
        }
        printf("%d\n",cot);
    }
}
