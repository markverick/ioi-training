#include<bits/stdc++.h>
using namespace std;
int n;
int a[100135],b[100135],x,y;
int bst[5000000];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    memset(bst,-1,sizeof bst);
    for(i=n;i>=1;i--)
    {
        scanf("%d",&a[i]);
        b[i]=~a[i];
    }
    int mc=-1,idx=1;
    for(i=20;i>=0;i--)
    {
        bst[idx]=0;
        idx*=2;
        if((a[1]|(1<<i))==a[1] )
            idx++;
    }
    bst[idx]=1;
    //printf("idx=%d\n",idx);
    for(j=2;j<=n;j++)
    {
        idx=1;
        for(i=20;i>=0;i--)
        {
            //printf("idx[%d] = %d\n",j,idx);
            if((b[j]|(1<<i))==b[j] )
            {
                if(bst[idx*2+1]==-1)
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
                if(bst[idx*2]==-1)
                {
                    idx=idx*2+1;
                }
                else
                {
                    idx=idx*2;
                }
            }
        }
        //printf("%d %d %d %d\n",idx,bst[idx/8],bst[idx/2],bst[idx/2+1]);
        //printf("%d\n",bst[idx]);
        //printf("=%d\n",a[bst[idx]]^a[j]);
        if(mc<=(a[bst[idx]]^a[j]) )
        {
            mc=a[bst[idx]]^a[j];
            x=j;y=bst[idx];
        }
        idx=1;
        for(i=20;i>=0;i--)
        {
            bst[idx]=0;
            idx*=2;
            if((a[j]|(1<<i))==a[j] )
                idx++;
        }
        bst[idx]=j;
    }
    printf("%d %d %d",mc,n-x+1,n-y+1);
}
