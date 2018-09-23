#include<stdio.h>
#include<string.h>


int minstep(int x)
{
    int fst=0,lst=0;
    int q[100000];
    int jum[100000];
    bool hsh[100000];
    memset(q,0,sizeof q);
    memset(jum,0,sizeof jum);
    memset(hsh,0,sizeof hsh);
    //jum[x]=1;
    int n=x;
    q[lst++]=n;
    int out=0;
    int i,j,k;
    while(true)
    {
        //printf("%d\n",q[fst]);
        int a=q[fst];
        if(a==1)
        {
            out=fst;
            break;
        }
        fst++;
        if(hsh[a-1]==0)
        {
            hsh[a-1]=1;
            jum[a-1]=jum[a]+1;
            q[lst++]=a-1;
        }
        if(hsh[a/2]==0&&a%2==0)
        {
            hsh[a/2]=1;
            jum[a/2]=jum[a]+1;
            q[lst++]=a/2;
        }
        if(hsh[a/3]==0&&a%3==0)
        {
            hsh[a/3]=1;
            jum[a/3]=jum[a]+1;
            q[lst++]=a/3;
        }

    }
    return jum[1];
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",minstep(n));
}
