#include<bits/stdc++.h>
int x[2000],n,jum[2000];
int highest=0;
int fx(int idx,int length) //return the max of it
{
    if(jum[idx]>=0)
    {
        return jum[idx];
    }
    if(idx>=n)
    {
        if(jum[idx-1]>highest)
            highest=jum[idx-1];

        return jum[idx-1];
    }
    if(x[idx]>length)
    {
        return jum[idx] =  fx(idx+1,x[idx])+1;
    }
    return jum[idx] = fx(idx+1,length);
}
int main()
{
    int i;
    memset(jum,-1,2000);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    fx(0,0);
    printf("%d",highest);

}
