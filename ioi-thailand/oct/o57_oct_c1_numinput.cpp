#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1135],b[1135],c;
int num[1135];
int mn[1135],mc[1135];
int all=0;
int kp[1135];
int main()
{
    int i,j,k=1;
    scanf("%d %d",&n,&m);
    for(i=0;i<=n+5;i++)
    {
        mc[i]=0;mn[i]=1000000000;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        all+=a[i];
        for(j=1;j<=a[i];j++)
        {
            b[k++]=i;
        }
    }
//    for(i=1;i<=all;i++)
//        printf("%d, ",b[i]);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&c);
        mc[b[c]]=max(mc[b[c]],c);
        mn[b[c]]=min(mn[b[c]],c);
    }
    kp[0]=1;
    for(i=0;i<all;i++)
    {
//        for(j=min(all,pos[b[i]+2]-1);j>=max(i+1,pos[b[i]+1]==100000000?0:pos[b[i]+1]);j--)
//        {
        //printf("=%d\n",mc[b[i]+1]);
        for(j=max(i+1,mc[b[i]+1]);j<=min(all,mn[b[i]+2]);j++)
        {
            printf("%d\n",j);
            if(b[j]==b[i]+1)
                kp[j]+=kp[i];
        }
            printf("%d\n",kp[i]);
    }
    printf("%d\n",kp[all-2]);
}
