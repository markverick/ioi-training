#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int steelcutting(int s, int n, int* q, int *p)
{
    int a[1200],maxy=0;
    int i,j,k;
    memset(a,-1,sizeof a);
    a[0]=0;
    for(i=0;i<n;i++)
    {
        for(j=s;j>=0;j--)
        {
            if(a[j]!=-1)
            {
                a[j+q[i]]=max(a[j+q[i]],a[j]+p[i]);
            }
        }
    }
    for(i=s;i>=0;i--)
    {
        maxy=max(maxy,a[i]);
    }
    return maxy;
}
int main()
{
    int p[120],q[120];
    int s,n;
    scanf("%d %d",&s,&n);
    int i,j,k;
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&q[i],&p[i]);
    }
    printf("%d",steelcutting(s,n,q,p));

}
