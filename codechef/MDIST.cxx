#include<bits/stdc++.h>
#define MP make_pair
#define X first
#define Y second
using namespace std;
pair<int,int> seg[5][400135];
pair<int,int> ar[5][400135];
int x,y,val;
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2,i;
    if(fst==lst)
    {
        for(i=0;i<4;i++)
        {
            seg[i][idx]=ar[i][fst];
        }
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    for(i=0;i<4;i++)
    {
        seg[i][idx].X=min(seg[i][idx*2].X,seg[i][idx*2+1].X);
        seg[i][idx].Y=max(seg[i][idx*2].Y,seg[i][idx*2+1].Y);
    }
}
void update(int idx,int fst,int lst,int tr)
{
    int mid=(fst+lst)/2,i;
    if(fst==lst)
    {
        seg[tr][idx]={val,val};
        return;
    }
    if(x<=mid)
    {
        update(idx*2,fst,mid,tr);
    }
    else
    {
        update(idx*2+1,mid+1,lst,tr);
    }
    seg[tr][idx].X=min(seg[tr][idx*2].X,seg[tr][idx*2+1].X);
    seg[tr][idx].Y=max(seg[tr][idx*2].Y,seg[tr][idx*2+1].Y);
    return;
}
pair<int,int> sum(int idx,int fst,int lst,int tree)
{
    int mid=(fst+lst)/2;
    if(fst>=x&&lst<=y) return seg[tree][idx];
    if(lst<x||fst>y) return {2000000005,-2000000005};
    pair<int,int> a,b;
    a=sum(idx*2,fst,mid,tree);
    b=sum(idx*2+1,mid+1,lst,tree);
    return MP(min(a.X,b.X),max(a.Y,b.Y));
}
int main()
{
    int i,j,k,n,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        ar[0][i]={a+b,a+b};
        ar[1][i]={-a+b,-a+b};
        ar[2][i]={a-b,a-b};
        ar[3][i]={-a-b,-a-b};
    }
    build(1,1,n);
    int Q;
    long long mc;
    pair<int,int> p;
    char ch[3];
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%s",ch);
        if(ch[0]=='U')
        {
            scanf("%d %d %d",&x,&a,&b);
            x++;
            val=a+b;update(1,1,n,0);
            val=-a+b;update(1,1,n,1);
            val=a-b;update(1,1,n,2);
            val=-a-b;update(1,1,n,3);
        }
        else
        {
            scanf("%d %d",&x,&y);
            x++;y++;
            mc=0;
            for(i=0;i<4;i++)
            {
                p=sum(1,1,n,i);
                mc=max(mc,(long long)p.Y-p.X);
            }
            printf("%lld\n",mc);
        }
    }
}
