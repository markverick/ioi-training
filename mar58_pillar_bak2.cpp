#include<bits/stdc++.h>
using namespace std;

int a[55000];
int n;
int hi=0;
int asc(int idx,int yn)
{
    printf("F");
    if(idx>=n)
    {
        return 0;
    }
    if(yn==0)
    {
        if(a[idx+2]-a[idx]>=2&&a[idx+2]-a[idx]<=4)
            if(a[idx+1]-a[idx]>=1&&a[idx+1]-a[idx]<=2)
                return max(asc(idx+1,0),asc(idx+2,1));
            else
                return asc(idx+2,1);
        else
            if(a[idx+1]-a[idx]>=1&&a[idx+1]-a[idx]<=2)
                return asc(idx+1,0);
            else
                return 0;
    }
    else
        if(a[idx+1]-a[idx]>=1&&a[idx+1]-a[idx]<=2)
            return asc(idx+1,1);
        else
            return 0;
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
        asc(0,0);
        printf("%d\n",hi);
    }
}
