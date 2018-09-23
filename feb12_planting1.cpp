#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int st[25000];
int fn[25000];
int main()
{
    int n;
    scanf("%d",&n);
    int i,j,k;
    int a,b,c,d;
    int hX,lX;
    int hY,lY;
    int hi,lo;
    for(i=0;i<=20005;i++)
    {
        st[i]=20005;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        a+=10000;b+=10000;c+=10000;d+=10000;
        hX=max(a,c);lX=min(a,c);hY=max(b,d);lY=min(b,d);
        for(j=lX;j<hX;j++)
        {
            st[j]=min(st[j],lY-1);
            fn[j]=max(fn[j],hY-1);
            //printf("%d %d\n",st[j],fn[j]);
        }
    }
   // system("pause");
    int sum=0;
    for(i=0;i<20005;i++)
    {
        if(st[i]!=20005)
        {
            //printf("%d\n",fn[i]-st[i]);
            sum+=fn[i]-st[i];
        }

    }
    printf("%d",sum);
}
