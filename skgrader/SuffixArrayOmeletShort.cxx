#include<bits/stdc++.h>
#define MP make_pair
#define X first
#define Y second
using namespace std;
char s[200135];
int sa[20][200135];
pair<pair<int,int>,int> p[200135];
int main()
{
	int n,i,I,j,k;
    scanf("%d",&n);
    scanf("%s",s);
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
    for(j=0;j<n;j++)
    {
        printf("%d ",sa[i][j]);
    }
}
