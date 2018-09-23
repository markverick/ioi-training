#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
char s[100135];
int rnk[100135],pos[100135],lcp[100135];
pair<pair<int,int>,int> p[100135];
int main()
{
    int i,j,k,len;
    scanf("%s",s);
    len=strlen(s);
    s[len-1]='a'-1;
    len++;
    for(i=0;i<len;i++)
        rnk[i]=s[i];
    for(i=1;i<=len;i*=2)
    {
        for(j=0;j<len;j++)
        {
            p[j].X.X=rnk[j];
            p[j].Y=j;
        }
        for(j=0;j<len-i;j++)
        {
            p[j].X.Y=rnk[i+j];
        }
        for(j=len-i;j<len;j++)
            p[j].X.Y=-1;
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
    scanf("%d",&Q);
    int mc=0,sum=0,a;
    while(Q--)
    {
        scanf("%d",&a);
        sum=1;mc=1;
        for(i=1;i<len;i++)
        {
            if(lcp[i]>=a)
                sum++;
            else
                sum=1;
            mc=max(mc,sum);
        }
        printf("%d\n",mc);
    }
}
