#include<bits/stdc++.h>
int main()
{
    int a,b,c,i,j;
    int x=0,y=0;
    while(scanf("%d",&a,&b)!=EOF)
    {
        c=a*b;
        x=0;y=0;
        for(i=0;true;i++)
        {
            x+=a;y+=b;
            if(x==c)
                x=0;
            if(y==c)
                y=0;
            if(x>=y)
                break;
        }
        printf("%d\n",i);
    }
}
