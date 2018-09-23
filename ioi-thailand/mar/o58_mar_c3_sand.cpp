#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
int n,m,qs[2135][2135],fs[2135][2135],x,y,tree,val;
void add(int tree,int x,int y,int val)
{
    qs[tree][x]+=val;
    qs[tree][y+1]-=val;
}
int main()
{
    int i,j,k,a,b,c,d,m,n,Q;
    scanf("%d %d %d",&m,&n,&Q);
    m+=1010;
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        a+=505;b+=505;
        val=c;x=b-d+1;y=b;tree=a;
        x=max(0,x);y=min(m-1,y);
        add(tree,x,y,val);
        val=-c;x=b+1;y=b+d;tree=a;
        x=max(0,x);y=min(m-1,y);
        add(tree,x,y,val);
        for(j=1;j<d;j++)
        {
            if(a+j>=m)
                break;
            val=c;x=b-d+1+j;y=b;tree=a+j;x=max(0,x);y=min(m-1,y);
            add(tree,x,y,val);
            val=-c;x=b+1;y=b+d-j;tree=a+j;x=max(0,x);y=min(m-1,y);
            add(tree,x,y,val);
        }
        for(j=1;j<d;j++)
        {
            if(a-j<0)
                break;
            val=c;x=b-d+1+j;y=b;tree=a-j;x=max(0,x);y=min(m-1,y);
            add(tree,x,y,val);
            val=-c;x=b+1;y=b+d-j;tree=a-j;x=max(0,x);y=min(m-1,y);
            add(tree,x,y,val);
        }
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        {
            fs[i][j]=fs[i][j-1]+qs[i][j];
        }
    }
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=m;j++)
        {
            fs[i][j]+=fs[i][j-1];
        }
    }
//    for(i=505;i<m-505;i++)
//    {
//        for(j=505;j<m-505;j++)
//        {
//            tree=i;x=0;y=j;
//            printf("%d ",fs[i][j]);
//        }
//        printf("\n");
//    }
    for(i=1;i<=Q;i++)
    {
        scanf("%d %d",&a,&b);
        a+=505;b+=505;
        tree=a;x=0;y=b;
        printf("%d\n",fs[a][b]);
    }
}
