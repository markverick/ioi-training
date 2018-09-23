#include<bits/stdc++.h>
using namespace std;
int n,m,cot=0;
int a[200],b[200];
int result[30];
void gen(int idx)
{
    if(idx==n+1)
    {
        int fu=0;
        for(int i=1;i<=m;i++)
        {
            if(result[a[i]]==1&&result[b[i]]==1)
            {
                fu=1;break;
            }
        }
        if(fu==0)
            cot++;
        return;
    }
    result[idx]=0;
    gen(idx+1);
    result[idx]=1;
    gen(idx+1);
}
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        cot=0;
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
        }
        gen(1);
        printf("%d\n",cot-1);
    }
}
