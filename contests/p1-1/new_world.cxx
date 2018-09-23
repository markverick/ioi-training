#include<bits/stdc++.h>
using namespace std;
int a[100135];
int main()
{
    int T,i,j,k,n,jump,fst,lst,mid,idx,cot,fu,u,mn;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&jump);
        mn=1000000000;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(&a[1],&a[n+1]);
        fst=0;lst=1000000000;
        while(fst<=lst)
        {
            mid=(fst+lst)/2;
            cot=0;idx=1;fu=0;
            while(1)
            {
                u=upper_bound(&a[1],&a[n+1],a[idx]+mid)-&a[0]-1;
                if(u==idx)
                {
                    fu=1;break;
                }
                else
                    idx=u;
                cot++;
                if(idx==n)
                {
                    if(cot<=jump)
                        fu=0;
                    else
                        fu=1;
                    break;
                }
            }
            if(fu==0)
            {
                mn=min(mn,mid);
                lst=mid-1;
            }
            else
            {
                fst=mid+1;
            }
        }
        printf("%d\n",mn);
    }
}
