#include<bits/stdc++.h>
int maps[120000];
int highest=0;
int n;
int p,q;
int jum[120000];
int omelet(int idx)
{
    if(jum[idx]>=0)
    {
        return jum[idx];
    }
    if(idx>=n)
    {
        return 0;
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
    memset(jum,-1,120000);
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&maps[i]);
    }
    highest=omelet(0);
    printf("%d",highest);
}
