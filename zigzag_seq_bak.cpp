#include<bits/stdc++.h>
int seq[100];
int len;
int fx(int idx,int now) //return number of seq
{
    if(idx>=len)
    {
        return 0;
    }
    if(idx%2==0)
    {
        if(now<seq[idx])
        {
            return fx(idx+1,seq[idx])+1;
        }
        else
        {
            return fx(idx+1,now);
        }
    }
    else if(idx%2==1)
    {
        if(now>seq[idx])
        {
            return fx(idx+1,seq[idx])+1;
        }
        else
        {
            return fx(idx+1,now);
        }
    }
}
int main()
{
    int n,i;
    for(i=0;scanf("%d",&seq[i])!=EOF;i++);
    len=i;
    for(i=0;i<len;i++)
    {
        printf("%d\n",fx(i,seq[i]));
    }

    //printf("%d",fx2(0,seq[0]));
}
