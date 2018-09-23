#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int nxt[1000135];
int Min[1000135];
int hsh[1000135];
int a[1000135];
int n;
pair<int,int> order[1000135];
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<=1000000;i++)
    {
        Min[i]=1000005;
        nxt[i]=i;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        order[i]=make_pair(a[i],-i);
    }
    sort(&order[1],&order[n+1]);
    for(i=n;i>=1;i--)
    {
        if(Min[a[i]-1]!=1000005)
        {
            nxt[i]=Min[a[i]-1];
        }
        Min[a[i]]=min(Min[a[i]],i);
//        printf("%d\n",nxt[i]);
    }
//    for(i=1;i<=n;i++)
//    {
//        printf("%d ",nxt[i]);
//    }
    int x,cot=0;
    for(i=n;i>=1;i--)
    {
        x=-order[i].Y;
        if(hsh[x]==1)
            continue;
        cot++;
        hsh[x]=1;
        while(nxt[x]!=x)
        {
            hsh[x]=1;
            x=nxt[x];
            hsh[x]=1;
        }
    }
    printf("%d",cot);
}
