#include<bits/stdc++.h>
#define M 1440
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int hx[2000],hy[2000];
char day[10][12]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,x,dx,y,dy,a,b,loop=0;
	scanf("%d:%d",&a,&b);
	x=a*60+b;
	scanf("%d:%d",&a,&b);
	y=a*60+b;
	scanf("%d:%d",&a,&b);
	dx=a*60+b;
	scanf("%d:%d",&a,&b);
	dy=a*60+b;
	i=x;
	while(135)
    {
        if(hx[i]==1)
            break;
        hx[i]=1;
        i=(i+dx)%M;
    }
    loop=i;
	i=y;
	while(135)
    {
        if(hy[i]==1)
            break;
        hy[i]=1;
        i=(i+dy)%M;
    }
    loop=max(loop,i);
    int fk=0;//    system("pause");

    for(i=0;i<M;i++)
    {
        if(hx[i]&&hy[i])
        {
            fk=1;
            break;
        }
    }
    if(fk==0)
    {
        printf("Never");
        return 0;
    }
    a=x;b=y;
    int h;
    loop*=2;
    loop+=5;
    while(loop--)
    {
        if(a==b)
        {
            h=a%M;
            printf("%s\n%02d:%02d",day[(a/M)%7],h/60,h%60);
            return 0;
        }
        else if(a<b)
        {
            a+=dx;
        }
        else
        {
            b+=dy;
        }
    }
    printf("Never");
}
