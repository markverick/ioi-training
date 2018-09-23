#include<bits/stdc++.h>
using namespace std;
int a[100135];
int hsh[100135];
int dif[100135];
priority_queue<tuple<int,int,int> > pq;
int main()
{
    int n,i,j,k,u,x,y;
    scanf("%d",&n);
    for(i=1;i<=n*2+1;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(&a[1],&a[n*2+2]);
    for(i=1;i<=n*2+1;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    for(j=1;j<n*2+1;j++)
    {
        dif[j]=a[j+1]-a[j];
        pq.emplace(-dif[j],j,j+1);
        printf("%d ",dif[j]);
    }
    printf("\n");
    int sum=0;
    while(!pq.empty())
    {
        tie(u,x,y)=pq.top();
        u=-u;
        pq.pop();
        if(hsh[x]==0&&hsh[y]==0)
        {
            if(x-1>=1&&y+1<=n*2+1)
                pq.emplace(-a[y+1]+a[x-1],x-1,y+1);
            hsh[x]=1;hsh[y]=1;
            printf("U = %d, X = %d, Y = %d\n",u,x,y);
            sum+=u;
        }
    }
    printf("%d",sum);
}
