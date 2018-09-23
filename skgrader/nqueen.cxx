#include<bits/stdc++.h>
using namespace std;
int n,C=0,result[18],mp[70000],all;
void gen(int idx,int go,int up,int down)
{
    int i,j,pos,x;
    if(idx==n)
    {
        if(C<3)
        {
            for(i=0;i<n;i++)
            {
                printf("%d ",result[i]+1);
            }
            printf("\n");
        }
        C++;
        return;
    }
    pos=all&(~(go|up|down));
    x=0;
    while(pos>0)
    {
        x=pos&-pos;
        pos-=x;
        result[idx]=mp[x];
        gen(idx+1,go|x,(up|x)>>1,(down|x)<<1);
    }
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    all=(1<<n)-1;
    for(i=0;i<n;i++)
    {
        mp[1<<i]=i;
    }
    gen(0,0,0,0);
    printf("%d",C);
}
