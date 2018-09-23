#include<bits/stdc++.h>
using namespace std;
int n;
char a[60000];
int x[60000];
int sum=0;
int main()
{
    int T,t,i,j,k;
    scanf("%d",&T);

    for(t=0;t<T;t++)
    {
        memset(x,0,sizeof x);
        memset(a,0,sizeof a);
        a[0]='x';
        sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
            sum+=x[i];
        }
        for(i=0;i<n;i++)
        {
            for(j=51000;j>=0;j--)
            {
                if(a[j]=='x')
                {
                    a[j+x[i]]='x';
                }
            }
        }
        int lo=sum+1;
        for(i=0;i<=sum;i++)
        {
            if(a[i]=='x'&&abs(sum-i-i)<lo)
            {
                lo=abs(sum-i-i);
            }
        }
        printf("%d\n",lo);
    }
}
