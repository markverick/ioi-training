#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
int N,Q;
char in[2];
int uf[120000];
int p[220000];
int h[220000];
int fnd(int x)
{
    while(x!=p[x])
    {
        x=p[x];
        //printf("%d %d\n",x,p[x]);
    }
    return x;
}
void uni(int x,int y)
{
    int px=fnd(x);
    int py=fnd(y);
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
    int i,j,k;
    scanf("%d %d",&N,&Q);
    for(i=1;i<=N;i++)
    {
        p[i]=i;
    }
    for(i=0;i<Q;i++)
    {
        scanf("%s",in);
        if(in[0]=='c')
        {
            int a,b;
            scanf("%d %d",&a,&b);
            uni(a,b);
        }
        else if(in[0]=='q')
        {
            int a,b;
            scanf("%d %d",&a,&b);
            if(fnd(a)==fnd(b))
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }
    }
}
