#include<bits/stdc++.h>
using namespace std;
int hsh[135];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int a,b,c,d,i,cot=0;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    for(i=a;i<b;i++)
        hsh[i]=1;
    for(i=c;i<d;i++)
        hsh[i]=1;
    for(i=0;i<=101;i++)
        cot+=hsh[i];
    printf("%d",cot);
}
