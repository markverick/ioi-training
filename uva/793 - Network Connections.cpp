#include<bits/stdc++.h>
int p[100000],h[100000];
int v,a,b,Y=0,N=0;
int xx,yy;
int find_(int x)
{
    while(x!=p[x])x=p[x];
    return x;
}
void union_(int x,int y)
{
    xx = find_(x);
    yy = find_(y);
    if(xx!=yy)
    {
        if(h[xx]==h[yy])
        {
            p[yy]=xx;
            h[xx]++;
        }
        else if(h[xx]>h[yy])
        {
            p[yy]=xx;
        }
        else if(h[xx]<h[yy])
        {
            p[xx]=yy;
        }
    }
}
int main()
{

    char in[3];
    int i,j,k;
    scanf("%d",&v);
    for(i=0;i<=v;i++)
    {
        p[i]=i;
    }
    while(scanf("%s",in)!=EOF)
    {
        if(in[0]=='c')
        {
            scanf("%d %d",&a,&b);
            union_(a,b);
        }
        else if(in[0]=='q')
        {
            scanf("%d %d",&a,&b);
            if(find_(a)==find_(b))
            {
                Y++;
            }
            else
            {
                N++;
            }
        }
        else
        {
            printf("YOU SUCK\n");
        }
    }
    printf("%d,%d",Y,N);
}
