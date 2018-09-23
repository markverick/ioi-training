#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int s[20135];
int rnk[23][20135],pos[20135],lcp[20135];
pair<pair<int,int>,int> p[20135];
int main()
{
    int i,j,k,c=0,len,mc=0;
    scanf("%d",&len);
    for(i=0;i<len;i++)
    {
        scanf("%d",&s[i]);
//        s[i]++;
        s[len+i]=s[i];
    }
    len*=2;
//    s[len]='a'-1;
//    len++;
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
    for(i=0;i<len;i++)
    {
        pos[rnk[baw][i]]=i;
    }

    int idx=0,Q,lai=0;
    for(i=0;i<len;i++)
    {
        idx=0;
        if(lai==0)
        {
            if(pos[i]<len/2)
            {
                lai=i;
            }
            continue;
        }
        if(pos[i]<len/2)
        {
//            printf("%d %d\n",i,lai);
            for(j=baw;j>=0;j--)
            {
                if(pos[i]+idx<len&&pos[lai]+idx<len&&rnk[j][pos[i]+idx]==rnk[j][pos[lai]+idx])
                    idx+=(1<<j);
            }
            lai=i;
//            printf("= %d\n",idx);
            lcp[i]=idx;
        }
    }
    lai=0;
    for(i=0;i<len;i++)
    {
//        printf("%d\n",lcp[i]);
        mc=max(mc,lcp[i]);
    }
    if(mc>=len/2)
        printf("-1");
    else
        printf("%d",mc);
}
