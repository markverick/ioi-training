#include<bits/stdc++.h>
using namespace std;
int out[8000];
int main()
{
    int n,k,i,x,t,len=0;
    scanf("%d %d",&n,&k);
    for(t=0;t<n;t++)
    {
        x=k%(n-t);
        if(x==0)x=n-t;
        len++;
        for(i=0;i<len;i++)
        {

            if(x>=out[i])
            {
                out[len]=x+i;
                break;
            }
        }
        sort(&out[1],&out[len+1]);
        printf("%d\n",x);
    }
}
