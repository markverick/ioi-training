#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
char s[100135];
int rnk[23][100135],pos[100135],lcp[100135];
pair<pair<int,int>,int> p[100135];
int main()
{
    int i,j,k,c=0,len;
    scanf("%s",s);
    len=strlen(s);
    s[len]='a'-1;
    len++;
    for(i=0;i<len;i++)
        rnk[0][i]=s[i];
    for(i=1,c=1;i<=len;i*=2,c++)
    {
        for(j=0;j<len;j++)
        {
            p[j].X.X=rnk[c-1][j];
            p[j].Y=j;
        }
        for(j=0;j<len-i;j++)
        {
            p[j].X.Y=rnk[c-1][i+j];
        }
        for(j=len-i;j<len;j++)
            p[j].X.Y=-1;
        sort(&p[0],&p[len]);
        k=0;
        rnk[c][p[0].Y]=0;
        for(j=1;j<len;j++)
        {
            if(p[j-1].X!=p[j].X)
                k++;
            rnk[c][p[j].Y]=k;
        }
    }
    int baw=c-1;
    for(i=0;i<len;i++)
    {
        pos[rnk[baw][i]]=i;
    }
    int idx=0,Q;
    for(i=1;i<len;i++)
    {
        idx=0;
        for(j=baw;j>=0;j--)
        {
            if(pos[i]+idx<len&&pos[i-1]+idx<len&&rnk[j][pos[i]+idx]==rnk[j][pos[i-1]+idx])
                idx+=(1<<j);
        }
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
            {
                sum++;
            }
            else
            {
                sum=1;
            }
            mc=max(mc,sum);
        }
        printf("%d\n",mc);
    }
}
