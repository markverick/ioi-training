#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int s[100005];
int rnk[100005],pos[100005],lcp[100005];
pair<pair<int,int>,int> p[100005];
int main()
{
    int n,i,j,k,len;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
        s[n+i]=s[i];
    }
    len=n;
    for(i=0;i<len;i++)
        rnk[i]=s[i];
    for(i=1;i<=len;i*=2)
    {
        for(j=0;j<len;j++)
        {
            p[j].X.X=rnk[j];
            p[j].Y=j;
        }
        for(j=0;j<len;j++)
        {
            p[j].X.Y=rnk[i+j];
        }
        sort(&p[0],&p[len]);
        k=0;
        rnk[p[0].Y]=0;
        for(j=1;j<len;j++)
        {
            if(p[j-1].X!=p[j].X)
                k++;
            rnk[p[j].Y]=k;
        }
    }
    for(i=0;i<len;i++)
    {
        pos[rnk[i]]=i;
    }
    int idx=0,Q;
    for(i=1;i<len;i++)
    {
        while(idx>0&&s[pos[i]+idx]!=s[pos[i-1]+idx])
            idx--;
        while(s[pos[i]+idx]==s[pos[i-1]+idx])
            idx++;
        lcp[i]=idx;
    }
    int mc=0;
    for(i=1;i<len;i++)
//        printf("%d\n",lcp[i]),
        mc=max(mc,lcp[i]);
    printf("%d",mc);

}
