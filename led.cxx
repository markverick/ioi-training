#include<bits/stdc++.h>
using namespace std;
char str[45];
long long a[160];
long long b[160];
long long c[160];
queue<vector<int> > q;
vector<int> start;
int main()
{
    int T,n,m,i,j,k,len,idx;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            for(j=0;j<m;j++)
            {
                a[i]*=2;
                a[i]+=str[j]-'0';
            }
        }
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            for(j=0;j<m;j++)
            {
                b[i]*=2;
                b[i]+=str[j]-'0';
            }
        }
        sort(&a[0],&a[n]);
        sort(&b[0],&b[n]);
        long long xr;//__builtin_popcountll(long long)
        int fu=0;
        int mn=1000000000;
        for(i=0;i<n;i++)
        {
            fu=0;
            xr=b[i]^a[0];
            for(j=0;j<n;j++)
            {
                c[j]=xr^a[j];
            }
            sort(&c[0],&c[n]);
            for(j=0;j<n;j++)
            {
                if(c[j]!=b[j])
                {
                    fu=1;break;
                }
            }
            if(fu==0)
            {
                mn=min(mn,__builtin_popcountll(xr));
            }
        }
        if(mn==1000000000)
            printf("NO\n");
        else
            printf("%d\n",mn);
//        printf("A = ");
//        for(i=0;i<n;i++)
//            printf("%d ",a[i]);
//        printf("\nB = ");
//        for(i=0;i<n;i++)
//            printf("%d ",b[i]);
//        printf("\n");

    }
}
