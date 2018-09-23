#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n;
pair<int,int> a[15];
int main()

{
    int i,j,k,mc=0,T=0,fst,lst,mid,time,fu=0;
    while(scanf("%d",&n)!=EOF)
    {
        T++;
        mc=0;
        memset(a,0,sizeof a);
        if(n==0)
            return 0;

        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&a[i].X,&a[i].Y);
            a[i].X*=960;
            a[i].Y*=960;
        }
        sort(&a[1],&a[n+1]);
        do
        {
            fst=0;lst=a[n].Y-a[1].X;time=a[1].X;fu=0;
            //printf("[%d ~ %d]\n",a[1].X,a[n].Y);
            while(fst<=lst)
            {
                mid=(fst+lst)/2;fu=0;time=a[1].X;
                //printf("%d <- %d -> %d = %f\n",fst,mid,lst,(double)mid/960);
                for(i=2;i<=n;i++)
                {
                    if(time+mid<=a[i].Y)
                    {
                        if(time+mid>=a[i].X)
                        {
                            time=time+mid;
                        }
                        else
                        {
                            time=a[i].X;
                        }
                    }
                    else
                    {
                        fu=1;
                        break;
                    }
                }
                if(fu==0)
                {
                    mc=max(mc,mid);
                    fst=mid+1;
                }
                else
                {
                    lst=mid-1;
                }
            }
        }
        while(next_permutation(&a[1],&a[n+1]));
        int out=(int)round((double)mc/16);
        printf("Case %d: %d:%02d\n",T,out/60,out%60);
    }
}
