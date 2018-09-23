#include<bits/stdc++.h>
#define MI 1000000000
#define EPS 0.000000001
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int main()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int T,i,j,k,xx,yya,yyb;
    double xa,ya,xb,yb,xc,yc,xd,yd;
    int fu;
    double mx,cx,my,cy,y,x;
    scanf("%d",&T);
    while(T--)
    {
        fu=0;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&xa,&ya,&xb,&yb,&xc,&yc,&xd,&yd);
        if(xc>xd)
            swap(xc,xd);
        if(yc<yd)
            swap(yc,yd);
        mx=(yb-ya)/(xb-xa);
        my=(xb-xa)/(yb-ya);
        cx=ya-xa*mx;
        cy=xa-ya*my;
        y=mx*xc+cx;
        if(min(xa,xb)-EPS<=xc&&max(xa,xb)+EPS>=xc&&y+EPS>=yd&&y-EPS<=yc)
            fu=1;
        y=mx*xd+cx;
        if(min(xa,xb)-EPS<=xd&&max(xa,xb)+EPS>=xd&&y+EPS>=yd&&y-EPS<=yc)
            fu=1;
        x=my*yc+cy;
        if(min(ya,yb)-EPS<=yc&&max(ya,yb)+EPS>=yc&&x+EPS>=xc&&x-EPS<=xd)
            fu=1;
        x=my*yd+cy;
        if(min(ya,yb)-EPS<=yd&&max(ya,yb)+EPS>=yd&&x+EPS>=xc&&x-EPS<=xd)
            fu=1;
        if(min(xa,xb)+EPS>=min(xc,xd)&&max(xa,xb)-EPS<=max(xc,xd)&&min(ya,yb)+EPS>=min(yc,yd)&&max(ya,yb)-EPS<=max(yc,yd))
            fu=1;
        if(fu==1)
            printf("T\n");
        else
            printf("F\n");
    }
}
