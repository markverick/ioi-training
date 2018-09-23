#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
char s[200135];
int sa[20][200135],I,n;
pair<pair<int,int>,int> p[200135];
int cmp(int x,int y)
{
    int i,sum=0;
    for(i=I;i>=0;i--)
    {
        if(max(x,y)+(1<<i)>=n)
            continue;
        if(sa[i][x]==sa[i][y])
        {
            x+=(1<<i);y+=(1<<i);
            sum+=(1<<i);
        }
    }
    return sum;
}
int main()
{
	int i,j,k,mc=0;
    scanf("%d %s",&n,s);
    for(j=0;j<n;j++)
        sa[0][j]=s[j];
    for(i=0;(1<<i)<n*2;i++)
    {
        I=(1<<i);
        for(j=0;j<n;j++)
            p[j]=MP(MP(sa[i][j],j+I<n?sa[i][j+I]:-1),j);
        sort(&p[0],&p[n]);
        k=0;sa[i+1][p[0].Y]=k;
        for(j=1;j<n;j++)
        {
            if(p[j].X!=p[j-1].X)
                k++;
            sa[i+1][p[j].Y]=k;
        }
    }
    I=i;
    for(j=1;j<n;j++)
        mc=max(mc,cmp(p[j-1].Y,p[j].Y));
    printf("%d",mc);
}
