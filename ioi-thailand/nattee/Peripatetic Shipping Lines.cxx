#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[135][135],b[135][135],slove[135];
vector<int> s[135],p[135];
vector<pair<int,int> > pi[135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,m,c;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
    {
        k=1;
        for(j=1;j<=m;j++)
        {
            scanf("%d",&c);
            if(c)
            {
                a[i][k]=c;
                pi[c].emplace_back(j,i);
                k++;
            }
        }
    }
    for(i=1;i<=n;i++)
        sort(pi[i].begin(),pi[i].end());
    for(i=1;i<=n;i++)
    {
        for(j=0;j<pi[i].size();j++)
        {
            p[i][j].emplace_back(pi[i][j].Y);
        }
    }
    for(i=n;i>=1;i--)
    {
        for(j=1;j<=n;j++)
        {
            s[j][n-i+1]=
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d > ",s[i][j]);
        printf("\n");
    }
    printf("\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d > ",pi[i][j-1].Y);
        printf("\n");
    }
    for(i=1;i<=n;i++)
        q.emplace(i,1);
    while(!q.empty())
    {
        tie(P,x)=q.top();
        q.pop();
        S=pi[P][x];
        for(i=1;i<=n;i++)
        {
            if()
        }
        if(xslove[S])
        if()
    }
}
