#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
char str[1000135];
int n;
int ms[1000135],d[1000135];
int main()
{
    int i,j,k,st,fu=0;
    scanf("%d",&n);
    scanf("%s",str+1);
    for(i=1;i<=n;i++)
    {
        if(str[i]=='A')
        {
            if(fu==0)
                st=i;
            fu=1;
            d[i]=-1;//str[i]=-1;
        }
        else
            d[i]=1;//str[i]=1;
        ms[i]=max(ms[i-1]+d[i],d[i]);
    }
    for(i=n;i>=st;i--)
    {
        if(str[i]=='B')
        {
            if(ms[i+1]<ms[i]&&ms[i]>2)
            cot+=2;
        }
    }
}
