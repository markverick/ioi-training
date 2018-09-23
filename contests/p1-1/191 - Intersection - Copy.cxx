#include<bits/stdc++.h>
#define sig 0.000001
using namespace std;

int main()
{
//    freopen("out.txt","w",stdout);
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
        if(min(xa,xb)-sig<=xc&&max(xa,xb)+sig>=xc&&y+sig>=yd&&y-sig<=yc)
            fu=1;
//        printf("%d\n",fu);
        y=mx*xd+cx;
        if(min(xa,xb)-sig<=xd&&max(xa,xb)+sig>=xd&&y+sig>=yd&&y-sig<=yc)
            fu=1;
//        printf("%d\n",fu);
        x=my*yc+cy;
        if(min(ya,yb)-sig<=yc&&max(ya,yb)+sig>=yc&&x+sig>=xc&&x-sig<=xd)
            fu=1;
//        printf("%d\n",fu);        x=my*yd+cy;
        if(min(ya,yb)-sig<=yd&&max(ya,yb)+sig>=yd&&x+sig>=xc&&x-sig<=xd)
            fu=1;
//        printf("%d\n",fu);
        if(min(xa,xb)+sig>=min(xc,xd)&&max(xa,xb)-sig<=max(xc,xd)&&min(ya,yb)+sig>=min(yc,yd)&&max(ya,yb)-sig<=max(yc,yd))
            fu=1;
        if(fu==1)
            printf("T\n");
        else
            printf("F\n");
    }
}
