#include<bits/stdc++.h>
#define N 1000005
using namespace std;
int fw[4][2*N];
void add(int x,int val,int op)
{
    x++;
    while(x<2*N)
    {
        fw[op][x]+=val;
        x+=x&-x;
    }
}
int sum(int x,int op)
{
    x++;
    int ss=0;
    while(x>0)
    {
        ss+=fw[op][x];
        x-=x&-x;
    }
    return ss;
}
int main()
{
    int t,n,k,i,j,x,y,r,c;
    long long res;
    scanf("%d",&t);
    while(t--)
    {
        memset(fw,0,sizeof fw);
        scanf("%d%d",&n,&k);
        for(i=0;i<=2*(n-1);i++)
        {
            if(i%2)
            {
                add(i,1,2);
                add(i,1,3);
            }
            else
            {
                add(i,1,0);
                add(i,1,1);
            }
        }
        res=0;
        while(k--)
        {
            scanf("%d%d",&x,&y);
            x--;
            y--;
            r=n-1+x-y;
            c=x+y;
            if(r%2)
            {
                if(sum(r,2)-sum(r-1,2)!=0)
                {
                    if(n%2) res+=sum(2*(n-1)-abs(n-1-r),3)-sum(abs(n-1-r)-1,3);
                    else res+=sum(2*(n-1)-abs(n-1-r),1)-sum(abs(n-1-r)-1,1);
                    add(r,-1,2);
                }
            }
            else
            {
                if(sum(r,0)-sum(r-1,0)!=0)
                {
                    if(n%2) res+=sum(2*(n-1)-abs(n-1-r),1)-sum(abs(n-1-r)-1,1);
                    else res+=sum(2*(n-1)-abs(n-1-r),3)-sum(abs(n-1-r)-1,3);
                    add(r,-1,0);
                }
            }
            if(c%2)
            {
                if(sum(c,3)-sum(c-1,3)!=0)
                {
                    if(n%2) res+=sum(2*(n-1)-abs(n-1-c),2)-sum(abs(n-1-c)-1,2);
                    else res+=sum(2*(n-1)-abs(n-1-c),0)-sum(abs(n-1-c)-1,0);
                    add(c,-1,3);
                }
            }
            else
            {
                if(sum(c,1)-sum(c-1,1)!=0)
                {
                    if(n%2) res+=sum(2*(n-1)-abs(n-1-c),0)-sum(abs(n-1-c)-1,0);
                    else res+=sum(2*(n-1)-abs(n-1-c),2)-sum(abs(n-1-c)-1,2);
                    add(c,-1,1);
                }
            }
        }
        printf("\t%lld\n",(long long)n*n-res);
    }

}
