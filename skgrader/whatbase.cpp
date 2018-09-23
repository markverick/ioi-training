#include<bits/stdc++.h>
using namespace std;
int aa[5];
int bb[5];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        aa[1]=a%10;a/=10;
        aa[2]=a%10;a/=10;
        aa[3]=a%10;a/=10;
        bb[1]=b%10;b/=10;
        bb[2]=b%10;b/=10;
        bb[3]=b%10;b/=10;
        int x=10,y=10;
        while(true)
        {
            if(aa[1]+aa[2]*x+aa[3]*x*x==bb[1]+bb[2]*y+bb[3]*y*y)
            {
                break;
            }
            else if(aa[1]+aa[2]*x+aa[3]*x*x<bb[1]+bb[2]*y+bb[3]*y*y)
                x++;
            else
                y++;
        }
        printf("%d %d\n",x,y);
    }
}
