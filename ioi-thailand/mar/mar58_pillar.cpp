#include<bits/stdc++.h>
using namespace std;

int a[55000];
int n;
int mc=0;
int idfnd[60000];
void asc(int idx,int yn,int hi)
{
    if(idx>=n)
    {
        mc=max(mc,hi);
        return;
    }
    if(yn==0)
    {
        if(a[idx+2]-a[idx]>=2&&a[idx+2]-a[idx]<=4)
            if(a[idx+1]-a[idx]>=1&&a[idx+1]-a[idx]<=2)
            {
                if(mc<hi+2)
                {
                    mc=hi+2;
                    idfnd[mc]=min(idfnd[mc],idx);
                }
                asc(idx+1,0,hi+1);
                asc(idx+2,1,hi+2);
                return;
            }
            else
            {
                if(mc<hi+2)
                {
                    mc=hi+2;
                    idfnd[mc]=min(idfnd[mc],idx);
                }
                asc(idx+2,1,hi+2);
                return;
            }
        else
            if(a[idx+1]-a[idx]>=1&&a[idx+1]-a[idx]<=2)
            {
                if(mc<hi+1)
                {
                    idfnd[hi+1]=idfnd[mc];
                    mc=hi+1;
                }
                asc(idx+1,0,hi+1);
                return;
            }
            else
            {
                asc(idx+1,0,0);
                return;
            }
    }
    else
        if(a[idx+1]-a[idx]>=1&&a[idx+1]-a[idx]<=2)
        {
            if(mc<hi+1)
            {
                idfnd[hi+1]=idfnd[mc];
                mc=hi+1;
            }
            asc(idx+1,1,hi+1);
            return;
        }
        else
        {
            asc(idx+1,1,0);
            return;
        }
}
void dsc(int idx,int yn,int hi)
{
    if(idx>=n)
    {
        mc=max(mc,hi);
        return;
    }
    if(yn==0)
    {
        if(a[idx]-a[idx+2]>=2&&a[idx]-a[idx+2]<=4)
            if(a[idx]-a[idx+2]>=1&&a[idx]-a[idx+2]<=2)
            {
                if(mc<hi+2)
                {
                    mc=hi+2;
                    idfnd[mc]=min(idfnd[mc],idx);
                }
                dsc(idx+1,0,hi+1);
                dsc(idx+2,1,hi+2);
                return;
            }
            else
            {
                if(mc<hi+2)
                {
                    mc=hi+2;
                    idfnd[mc]=min(idfnd[mc],idx);
                }
                dsc(idx+2,1,hi+2);
                return;
            }
        else
            if(a[idx]-a[idx+1]>=1&&a[idx]-a[idx+1]<=2)
            {
                if(mc<hi+1)
                {
                    idfnd[hi+1]=idfnd[mc];
                    mc=hi+1;
                }
                dsc(idx+1,0,hi+1);
                return;
            }
            else
            {
                dsc(idx+1,0,0);
                return;
            }
    }
    else
        if(a[idx]-a[idx+1]>=1&&a[idx]-a[idx+1]<=2)
        {
            if(mc<hi+1)
            {
                idfnd[hi+1]=idfnd[mc];
                mc=hi+1;
            }
            dsc(idx+1,1,hi+1);
            return;
        }
        else
        {
            dsc(idx+1,1,0);
            return;
        }

}
int main()
{
    int T,t;
    int i,j,k;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        mc=1;
        for(i=0;i<n;i++)
            idfnd[i]=1000000;
        asc(0,0,0);
        int a=mc+1,b=idfnd[mc]+1;
        //printf("=%d %d, ",mc+1,idfnd[mc]+1);

        for(i=0;i<n;i++)
            idfnd[i]=1000000;
        mc=1;
        dsc(0,0,0);
        int c=mc+1,d=idfnd[mc]+1;
        if(b<=d)
        {
            if(b==1000001)b=0;
            printf("%d %d\n",a,b);
        }
        else
        {
            if(d==1000001)d=0;
            printf("%d %d\n",c,d);
        }
        //printf("%d %d\n",mc+1,idfnd[mc]+1);

    }
}
