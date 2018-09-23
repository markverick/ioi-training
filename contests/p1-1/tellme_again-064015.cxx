#include<bits/stdc++.h>
using namespace std;
char a[120000],b[120000];
int main()
{
    int T,i,j,k,lA,lB;
    long long x=0,y=0;
    scanf("%d",&T);
    while(T--)
    {
        x=0;y=0;
        int cot=0;
        scanf("%s %s",a,b);
        lA=strlen(a);
        lB=strlen(b);
        for(i=0;i<lA;i++)
        {
            x*=131;
            x+=a[i];
        }
        long long mul=1;
        for(i=0;i<lA;i++)
        {
            mul*=131;
        }

       for(i=0;i<lB;i++)
       {
            y*=131;
            y+=b[i];
            if(i>=lA)
            {
                y-=b[i-lA]*mul;
            }
            if(y==x)
                cot++;
       }/*
       if(cot==0)
        printf("No\n");
        else
        printf("Yes\n");*/
       printf("%d\n",cot);
    }
}
