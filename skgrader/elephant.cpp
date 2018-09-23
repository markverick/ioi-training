#include<bits/stdc++.h>
int maps[120000];
int n;
int jum[120000];
int omelet(int idx)
{
    if(jum[idx]>=0)
    {
        return jum[idx];
    }
    if(idx==n)
    {
        return 0;
    }
    if(idx>n)
    {
        return -INFINITY;
    }
    else
    {
        return jum[idx] = std::max(omelet(idx+3)+maps[idx+2],omelet(idx+1));
        /*
        p=omelet(idx+3)+maps[idx+2];
        q=omelet(idx+1);
        if(p>q)
        {

            return p;
        }
        else
        {
            return q;
        }
*/
    }
}
int main()
{
    memset(jum,-1,sizeof(jum));
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {

        scanf("%d",&maps[i]);
    }
    /*for(i=n-1;i>=0;i--)
    {
        omelet(i);
    }*/
    printf("%d",omelet(0));
}
