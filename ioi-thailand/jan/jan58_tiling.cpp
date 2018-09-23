#include<bits/stdc++.h>

int main()
{
    //freopen("output.txt","w",stdout);
    int t,i,j,k,a,b,c,d;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        scanf("%d %d",&a,&b);
        for(i=3;true;i++)
        {
            d=i*2+(i-2)*2;
            c=(i-2)*(i-2);
            if(a<c||b<d)
            {
                printf("%d\n",i-1);
                break;
            }
        }
    }
}
