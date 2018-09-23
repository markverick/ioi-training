#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int brk[555],a[555],kp[555][5135];
int main()
{
	int T,n,i,j,k,l,sum=0,fst,mid,lst;
	memset(brk,-1,sizeof brk);
	scanf("%d %d",&T,&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
//    printf("sum = %d\n",sum);
    memset(kp,-1,sizeof kp);
    kp[0][0]=0;
    mid=T;
    for(i=1;i<=n;i++)
    {
        for(j=mid;j>=0;j--)
        {
            if(j-a[i]>=0)
            {
                if(kp[i-1][j-a[i]]>=0)
                    kp[i][j]=i;
            }
            if(kp[i-1][j]>=0)
                kp[i][j]=kp[i-1][j];
        }
    }
    for(i=mid;i>=0;i--)
    {
        if(kp[n][i]>=0)
        {
//            printf("!%d\n",i);
            if(sum-i<=mid)
            {
                k=kp[n][i];l=i;
                for(j=n;j>=1;j--)
                {
                    l-=a[k];
                    brk[k]=l;
//                    printf("[%d] from <%d> %d ~ %d\n",a[k],k,brk[k],brk[k]+a[k]);
                    k=kp[j][l];
                }
                l=0;
//                printf("\n");
                for(i=1;i<=n;i++)
                {
                    if(brk[i]==-1)
                    {
                        brk[i]=l;
//                        printf("[%d] from <%d> %d ~ %d\n",a[i],i,brk[i],brk[i]+a[i]);
                        l+=a[i];
                    }
                }
                for(i=1;i<=n;i++)
                {
                    printf("%d ",brk[i]);
                }
                return 0;
            }
        }
    }
}
