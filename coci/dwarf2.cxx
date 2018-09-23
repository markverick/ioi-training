#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[300135],x,y;
pair<int,int> seg[1200135];
vector<int> pos[10135];
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx]=MP(a[fst],1);
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    if(seg[idx*2].X==seg[idx*2+1].X)
        seg[idx]=MP(seg[idx*2].X,seg[idx*2].Y+seg[idx*2+1].Y);
    else
    {
        if(seg[idx*2].Y>=seg[idx*2+1].Y)
            seg[idx]=MP(seg[idx*2].X,seg[idx*2].Y-seg[idx*2+1].Y);
        else
            seg[idx]=MP(seg[idx*2+1].X,seg[idx*2+1].Y-seg[idx*2].Y);
    }
}
pair<int,int> Find(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(lst<x||fst>y)
    {
        return MP(0,0);
    }
    if(fst>=x&&lst<=y)
    {
        return seg[idx];
    }
    pair<int,int> p,q;
    p=Find(idx*2,fst,mid);
    q=Find(idx*2+1,mid+1,lst);
    if(p.X==q.X)
    {
        return MP(p.X,p.Y+q.Y);
    }
    else
    {
        if(p.X==0)
            return q;
        if(q.X==0)
            return p;
        if(p.Y>=q.Y)
            return MP(p.X,p.Y-q.Y);
        else
            return MP(q.X,q.Y-p.Y);
    }
}
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,c,m,maj;
	scanf("%d %d",&n,&c);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        pos[a[i]].emplace_back(i);
    }
    build(1,1,n);
    vector<int>::iterator L,R;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d %d",&x,&y);
        maj=Find(1,1,n).X;
        L=lower_bound(pos[maj].begin(),pos[maj].end(),x);
        R=upper_bound(pos[maj].begin(),pos[maj].end(),y);
        if(distance(L,R)>(y-x+1)/2)
            printf("yes %d\n",maj);
        else
            printf("no\n");
    }
}
