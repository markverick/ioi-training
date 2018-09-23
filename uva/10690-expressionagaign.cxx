#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[135],kp[135][10135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,m,all,mn,mc;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        mn=MI;mc=-MI;all=0;
        memset(kp,0,sizeof kp);
        for(i=1;i<=n+m;i++)
        {
            scanf("%d",&a[i]);
            a[i]+=50;
            all+=a[i];
        }
        kp[0][0]=1;
        for(i=1;i<=n+m;i++)
        {
            for(k=n;k>=1;k--)
            {
                for(j=10000;j>=0;j--)
                {
                    if(j+a[i]<=10000)
                    {
                        kp[k][j+a[i]]+=kp[k-1][j];
                    }
                }
            }
        }
        for(i=0;i<=10000;i++)
        {
            if(kp[n][i])
            {
                mn=min(mn,(i-n*50)*((all-i)-m*50));
                mc=max(mc,(i-n*50)*((all-i)-m*50));
            }
        }
        printf("%d %d\n",mc,mn);
    }
}
