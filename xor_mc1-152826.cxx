#include<bits/stdc++.h>
using namespace std;
int n;
int a[100135],b[100135],x,y;
int bst[3000000];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=2500000;i++)
    {
        bst[i]=-1;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=~a[i];
    }
    int mc=-1,idx=0;
    for(i=20;i>=0;i--)
    {
        bst[idx]=0;
        idx*=2;
        if((a[1]|(1<<i))==a[1] )
            idx++;
    }
    bst[idx]=1;
    for(j=2;j<=n;j++)
    {
        idx=0;
        for(i=20;i>=0;i--)
        {
            if((b[j]|(1<<i))==b[j] )
            {
                if(bst[idx*2+1]>0)
                {
                    //printf("%d %d\n",a[j],bst[idx*2+1]);
                    if( (a[j]^a[bst[idx*2+1] ] )>mc)
                    {
                        mc=max(mc,a[j]^a[bst[idx*2+1]] );y=j;x=bst[idx*2+1];
                    }
                    break;
                }
                else if(bst[idx*2+1]==-1)
                {
                    idx=idx*2;
                }
                else
                {
                    idx=idx*2+1;
                }
            }
            else
            {
                if(bst[idx*2]>0)
                {
                    //printf("%d %d\n",a[j],bst[idx*2]);
                    if(a[j]^a[bst[idx*2]]>mc)
                    {
                        mc=max(mc,a[j]^a[bst[idx*2]] );y=j;x=a[bst[idx*2]];
                    }
                    break;
                }
                else if(bst[idx*2]==-1)
                {
                    idx=idx*2+1;
                }
                else
                {
                    idx=idx*2;
                }
            }
        }
        idx=0;
        for(i=20;i>=0;i--)
        {
            bst[idx]=0;
            idx*=2;
            if((a[j]|(1<<i))==a[j] )
                idx++;
        }
        bst[idx]=j;
    }
    printf("%d %d %d",mc,x,y);
}
