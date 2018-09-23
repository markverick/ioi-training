#include<bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
#define mp make_pair
#define INF 1e9
int n,tb[1000][1000],Max[3000][3000],Min[3000][3000],x1,y1,x2,y2,x,y,v;
void build_y(int idx_x,int f_x,int l_x,int idx_y,int f_y,int l_y)
{
    if(f_y==l_y)
    {
        if(f_x==l_x)
        {
            Max[idx_x][idx_y]=tb[f_x][f_y];
            Min[idx_x][idx_y]=tb[f_x][f_y];
        }
        else
        {
            Max[idx_x][idx_y]=max(Max[idx_x*2][idx_y],Max[idx_x*2+1][idx_y]);
            Min[idx_x][idx_y]=min(Min[idx_x*2][idx_y],Min[idx_x*2+1][idx_y]);
        }
        return;
    }
    int mid=(f_y+l_y)/2;
    build_y(idx_x,f_x,l_x,idx_y*2,f_y,mid);
    build_y(idx_x,f_x,l_x,idx_y*2+1,mid+1,l_y);
    Max[idx_x][idx_y]=max(Max[idx_x][idx_y*2],Max[idx_x][idx_y*2+1]);
    Min[idx_x][idx_y]=min(Min[idx_x][idx_y*2],Min[idx_x][idx_y*2+1]);
}
void build_x(int idx_x,int f_x,int l_x)
{
    if(f_x!=l_x)
    {
        int mid=(f_x+l_x)/2;
        build_x(idx_x*2,f_x,mid);
        build_x(idx_x*2+1,mid+1,l_x);
    }
    build_y(idx_x,f_x,l_x,1,0,n-1);
}
void update_y(int idx_x,int f_x,int l_x,int idx_y,int f_y,int l_y)
{
    if(f_y==l_y)
    {
        if(f_x==l_x)
        {
            Max[idx_x][idx_y]=tb[f_x][f_y];
            Min[idx_x][idx_y]=tb[f_x][f_y];
        }
        else
        {
            Max[idx_x][idx_y]=max(Max[idx_x*2][idx_y],Max[idx_x*2+1][idx_y]);
            Min[idx_x][idx_y]=min(Min[idx_x*2][idx_y],Min[idx_x*2+1][idx_y]);
        }
        return;
    }
    int mid=(f_y+l_y)/2;
    if(f_y<=y&&y<=mid)update_y(idx_x,f_x,l_x,idx_y*2,f_y,mid);
    if(mid+1<=y&&y<=l_y)update_y(idx_x,f_x,l_x,idx_y*2+1,mid+1,l_y);
    Max[idx_x][idx_y]=max(Max[idx_x][idx_y*2],Max[idx_x][idx_y*2+1]);
    Min[idx_x][idx_y]=min(Min[idx_x][idx_y*2],Min[idx_x][idx_y*2+1]);
}
void update_x(int idx_x,int f_x,int l_x)
{
    if(f_x!=l_x)
    {
        int mid=(f_x+l_x)/2;
        if(f_x<=x&&x<=mid)update_x(idx_x*2,f_x,mid);
        if(mid+1<=x&&x<=l_x)update_x(idx_x*2+1,mid+1,l_x);
    }
    update_y(idx_x,f_x,l_x,1,0,n-1);
}
pii query_y(int idx_x,int f_x,int l_x,int idx_y,int f_y,int l_y)
{
    if(l_y<y1||y2<f_y)return mp(-INF,INF); 
    if(y1<=f_y&&l_y<=y2)
    {
        return mp(Max[idx_x][idx_y],Min[idx_x][idx_y]);
    }
    int mid=(f_y+l_y)/2;
    pii a,b;
    a=query_y(idx_x,f_x,l_x,idx_y*2,f_y,mid);
    b=query_y(idx_x,f_x,l_x,idx_y*2+1,mid+1,l_y);
    return mp(max(a.X,b.X),min(a.Y,b.Y));
}
pii query_x(int idx_x,int f_x,int l_x)
{
    if(l_x<x1||x2<f_x)return mp(-INF,INF);
    if(x1<=f_x&&l_x<=x2)
    {
        return query_y(idx_x,f_x,l_x,1,0,n-1);
    }
    int mid=(f_x+l_x)/2;
    pii a,b;
    a=query_x(idx_x*2,f_x,mid);
    b=query_x(idx_x*2+1,mid+1,l_x);
    return mp(max(a.X,b.X),min(a.Y,b.Y));
}
