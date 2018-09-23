#include<bits/stdc++.h>

int a[1200];
int hsh[12000];
int main()
{
    int T,t,i,j,k,n;
    scanf("%d",&T);
    int idx=0;
    for(t=0;t<T;t++)
    {
        idx=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(hsh[a[i]]==0)
                lis[idx++]=a[i];
            hsh[a[i]]++;
        }
        sort(&lis[0],&lst[idx]);
        for(i=0;true;i++)
        {
            for(j=0;j<idx;j++)
            {
                int c=lis[j]
            }
            if(hsh[i+1<=
        }
    }
}
