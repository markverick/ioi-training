#include<bits/stdc++.h>
using namespace std;
char str[1200000];
int len;
int L[1200000],R[1200000];
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        len=strlen(str);
        L[0]=0;long long x=0,y=0;
        for(i=1;i<len;i++)
        {
            if(str[i-1]=='O')
                L[i]=L[i-1]+1;
            else
            {
                L[i]=L[i-1];
            }
            if(str[i]=='Z')
                x+=L[i];

        }


        R[len-1]=0;
        for(i=len-2;i>=0;i--)
        {
            if(str[i+1]=='O')
                R[i]=R[i+1]+1;
            else
            {
                R[i]=R[i+1];
            }
            if(str[i]=='Z')
                y+=R[i];
        }
        printf("%lld\n",min(x,y));
    }
}
