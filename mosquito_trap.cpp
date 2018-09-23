#include<bits/stdc++.h>
int main()
{
    int n;
    int i,a,b;
    int lowX=300,highX=-100,lowY=300,highY=-100;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        if(a<lowX)lowX=a;
        if(b<lowY)lowY=b;
        if(a>highX)highX=a;
        if(b>highY)highY=b;
    }
    if(highX-lowX>highY-lowY)
    {
        printf("%d",(highX-lowX)*(highX-lowX));
    }
    else
    {
        printf("%d",(highY-lowY)*(highY-lowY));
    }

}
