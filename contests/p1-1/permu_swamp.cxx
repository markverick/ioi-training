#include<bits/stdc++.h>
using namespace std;
int p[10135],h[10135],a[10135],b[10135],la[10135],lb[10135];
int Find(int x)
{
    while(p[x]!=x)
    {
        x=p[x];
    }
    return x;
}
void Union(int x,int y)
{
    x=Find(x);y=Find(y);
    if(h[x]<=h[y])
    {
        p[x]=y;
        h[y]=max(h[y],h[x]+1);
    }
    else
    {
        p[y]=x;
        h[x]=max(h[x],h[y+1]);
    }
    return;
}
int main()
{
    int T,t,i,j,k,n,m,c,d;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            p[i]=i;
            h[i]=1;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            la[a[i]]=i;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            lb[b[i]]=i;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&c,&d);
            Union(c,d);
        }
        int fu=0;
        for(i=1;i<=n;i++)
        {
//            printf("%d %d\n",la[i],lb[i]);
            if(Find(la[i])!=Find(lb[i]))
            {
                fu=1;
            }
        }
        if(fu==1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
}
