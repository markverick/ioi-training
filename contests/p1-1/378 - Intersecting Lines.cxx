#include<bits/stdc++.h>
#define sig 0.00001
using namespace std;

int main()
{
//    freopen("out.txt","w",stdout);
    int T,i,j,k,xx,yya,yyb;
    double xa,ya,xb,yb,xc,yc,xd,yd;
    int fu;
    double mxa,mya,mxb,myb,cxa,cxb,cya,cyb;
    scanf("%d",&T);
    printf("INTERSECTING LINES OUTPUT\n");
    while(T--)
    {
        fu=0;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&xa,&ya,&xb,&yb,&xc,&yc,&xd,&yd);
        mxa=(yb-ya)/(xb-xa);
        mya=(xb-xa)/(yb-ya);
        cxa=ya-xa*mxa;
        cya=xa-ya*mya;
        mxb=(yd-yc)/(xd-xc);
        myb=(xd-xc)/(yd-yc);
        cxb=yc-xc*mxb;
        cyb=xc-yc*myb;
        if(abs(xb-xa)<=sig)
        {
            if(abs(xd-xc)<=sig)
            {
                if(abs(xb-xd)<=sig)
                    printf("LINE\n");
                else
                    printf("NONE\n");
            }
            else
            {
                printf("POINT %.2f %.2f\n",xb,mxb*xb+cxb);
            }
        }
        else
        {
            if(abs(xd-xc)<=sig)
            {
                printf("POINT %.2f %.2f\n",xd,mxa*xd+cxa);
            }
            else
            {
                if(abs(mxa-mxb)<=sig)
                {
                    if(abs(cxa-cxb)<=sig)
                        printf("LINE\n");
                    else
                        printf("NONE\n");
                }
                else
                {
                    printf("POINT %.2f %.2f\n",(cxa-cxb)/(mxb-mxa),cxa+mxa*((cxa-cxb)/(mxb-mxa)));
                }
            }
        }
    }
    printf("END OF OUTPUT\n");
}

