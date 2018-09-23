#include<bits/stdc++.h>
using namespace std;
int n,x,y,addVal,a,b,c,d,i,summation,toAdd,mn,mc;
int st[4194305];
void add(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    st[idx]+=addVal;
    if(fst>=lst)
        return;
    if(toAdd<=mid)
        add(idx*2,fst,mid);
    else
        add(idx*2+1,mid+1,lst);
    return;
}
int sum(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst>lst)
        return 0;
    if(y<fst||x>lst&&(fst>=mn||lst<=mc))
    {
        return 0;
    }
    if(x<=fst&&y>=lst&&fst>=mn&&lst<=mc)
    {
        return st[idx];
    }

    return sum(idx*2,fst,mid)+sum(idx*2+1,mid+1,lst);
}
int main()
{
    int ch;
    while(scanf("%d",&ch)!=EOF)
    {
        switch (ch)
        {
        case 0:
            scanf("%d",&n);
            break;
        case 1:
            scanf("%d %d %d",&x,&y,&addVal);
            toAdd=x*n+y;
            add(0,0,n*n-1);
            break;
        case 2:
            scanf("%d %d %d %d",&a,&b,&c,&d);
            summation=0;
            for(i=a;i<=c;i++)
            {
                x=i*n+b;
                y=i*n+d;
                mn=i*n;
                mc=i*n+n-1;
                summation+=sum(0,0,n*n-1);
            }
            printf("%d\n",summation);
            break;
        case 3:
            return 0;
            break;
        }
    }
}
