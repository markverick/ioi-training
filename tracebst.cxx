#include<bits/stdc++.h>
using namespace std;
int out[100135];
int R[100135];
int L[100135];
int i,j,k;
char str[100135];
int lai=1;
int zum[100135];
int hsh[100135];
void gen(int idx)
{
    if(L[idx]!=0)
        gen(L[idx]);
    out[idx]=lai++;
    if(R[idx]!=0)
        gen(R[idx]);
}
int main()
{
    int n,idx,len;
    scanf("%d",&n);
    scanf("%*s");
    for(i=2;i<=n;i++)
    {
        scanf("%s",str);
        len=strlen(str);
        idx=1;
        for(j=0;j<len-2;j++)
        {
            if(str[j]=='R')
            {
                idx=R[idx];
            }
            else
            {
                idx=L[idx];
            }
        }
        if(str[len-2]=='R')
        {
            if(R[idx]==0)
                R[idx]=i;
            else zum[i]=R[idx];
        }
        else
        {
            if(L[idx]==0)
                L[idx]=i;
            else zum[i]=L[idx];
        }
    }
    gen(1);
    for(i=1;i<=n;i++)
    {
        if(zum[i]!=0)
        {
            out[i]=out[zum[i]];
        }
    }
    for(i=1;i<=n;i++)
        printf("%d\n",out[i]);
}
