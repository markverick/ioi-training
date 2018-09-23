#include<stdio.h>
int p[200005],h[200005];
int find(int x)
{
    while(x!=p[x])
    {
        x=p[x];
    }
    return x;
}
void uniony(int x,int y)
{
    int px,py;
    px=find(x);
    py=find(y);
    if(px!=py)
    {
        if(h[px]>=h[py])
        {
            p[py]=px;
            if(h[px]==h[py])
                h[px]++;
        }
        else
            p[px]=py;
    }

}
int main()
{
    int n,q,x,y,i;
    char op[5];
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++)
    {
        p[i]=i;
    }
    for(i=0;i<q;i++)
    {
        scanf("%s",op);
        scanf("%d%d",&x,&y);
        if(op[0]=='q')
        {
            if(find(x)==find(y))
                printf("yes\n");
            else
                printf("no\n");
        }
        else
        {
            uniony(x,y);
        }
    }
}
