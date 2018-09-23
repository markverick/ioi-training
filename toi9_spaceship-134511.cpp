#include<bits/stdc++.h>
using namespace std;
int xs,ys,zs,n,m;
tuple<int,int,int> pos[22];
tuple<int,int,int> v[22];
inline int len(int x1,int y1,int z1,int x2,int y2,int z2)
{
    return abs(x2-x1)*abs(x2-x1)+abs(y2-y1)*abs(y2-y1)+abs(z2-z1)*abs(z2-z1);
}
map<tuple<short,short,short>,int > jum[22][2050];
int dp(int idx,int bitmask,int a,int b,int c)
{
    //printf("%d %d %d %d %d\n",idx,bitmask,a,b,c);
    if(a>=n&&b>=n&&c>=n)
    {
        return 0;
    }
    if(jum[idx][bitmask].find(make_tuple(a,b,c))!=jum[idx][bitmask].end())
        return jum[idx][bitmask][make_tuple(a,b,c)];
    //printf("%d %d %d %d\n",idx,a,b,c);
    int mn=1000000000;
    int i,j;
    int ai,bi,ci,dist;
    int x0,y0,z0;
    int xi,yi,zi;
    tie(x0,y0,z0)=pos[idx];

    for(i=1;i<=m;i++)
    {
        if((bitmask|(1<<(i-1)))==bitmask)
        {
            //printf("%d==%d\n",bitmask|(1<<(i-1)),bitmask);
            continue;
        }

        tie(ai,bi,ci)=v[i];
        tie(xi,yi,zi)=pos[i];
        dist=len(x0,y0,z0,xi,yi,zi);
        //printf("abci = %d %d %d\n",ai,bi,ci);
        //printf("xyzi = %d %d %d\n",xi,yi,zi);
        //printf("%d\n",dist);
        //printf("%d => %d\n",bitmask,bitmask|(1<<(i-1)));
        mn=min(mn,dp(i,bitmask|(1<<(i-1)),a+ai,b+bi,c+ci)+dist);
    }
    return jum[idx][bitmask][make_tuple(a,b,c)]=mn;
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    scanf("%d %d %d",&xs,&ys,&zs);
    pos[0]=make_tuple(xs,ys,zs);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        pos[i]=make_tuple(a,b,c);
        scanf("%d %d %d",&a,&b,&c);
        v[i]=make_tuple(a,b,c);
    }
    //sort(&v[0],&v[m]);
    printf("%d\n",dp(0,0,0,0,0));
}
