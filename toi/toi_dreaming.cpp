#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000],c[1000];
char asuck[1000],bsuck[1000];
int lA,lB;
int main()
{
    int i,idx;
    scanf("%s %s",asuck,bsuck);
    lA=strlen(asuck);
    lB=strlen(bsuck);
    for(i=0;i<lA;i++)
    {
        a[i]=asuck[i]-'0';
    }
    for(i=0;i<lB;i++)
    {
        b[i]=bsuck[i]-'0';
    }
    int bufA,bufB;
    //printf("%d\n",(lA-idx-1>=0)?(a[lA-idx-1]):(0) +(lB-idx-1>=0)?(b[lB-idx-1]):(0));
    //printf("%d\n",((a[lA-idx-1]+b[lB-idx-1])%10));
    for(idx=0;idx<max(lA,lB);idx++)
    {
        bufA=lA-idx-1;
        bufB=lB-idx-1;
        bufA>=0?bufA:999;
        bufB>=0?bufB:999;
        if( a[bufA] + b[bufB] >=10  )
        {
            //if(idx==0)printf("%d\n",(lA-idx-1>=0)?(a[lA-idx-1]):(0) +(lB-idx-1>=0)?(b[lB-idx-1]):(0) >=10);
            c[idx]=(a[bufA]+b[bufB])%10 ;
            lA>lB?a[bufA-1]++:b[bufB-1]++;
        }
        else
        {
            c[idx]=(a[bufA]+b[bufB]);
        }

    }/*
    if(lA>lB)
    {
        for(i=lA-lB-1;i>=0;i--)
        {
            c[idx++]=a[i];
        }
    }
    else if(lB>lA)
    {
        for(i=lB-lA-0;i>=0;i--)
        {
            c[idx++]=b[i];
        }
    }
    else
    {
        if(a[lA-idx]+b[lB-idx]>=10)
        {

        }
    }*/
    for(i=max(lA,lB)-1;i>=0;i--)
    {
        printf("%d",c[i]);
    }

}
