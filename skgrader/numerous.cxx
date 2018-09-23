#include<bits/stdc++.h>
using namespace std;

char str[1000135];
int ms[1000135];
int main()
{
    int T,i,j,k,len,idx;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str+1);
        len=strlen(str+1);
        ms[0]=1;
        for(i=1;i<=len;i++)
        {
            if(str[i]=='S')
            {
                ms[i]=max(ms[i-1]-1,0);
            }
            else
            {
                ms[i]=ms[i-1]+1;
            }
            //printf("%d ",ms[i]);

        }
        //cout <<"\n";
        int mc=0,sum=0;
        for(i=1;i<=len;i++)
        {
            mc=max(mc,ms[i]);
            if(str[i]=='S')
                sum++;
        }
        printf("%d\n",mc+sum);
        memset(ms,0,sizeof ms);
    }
}
