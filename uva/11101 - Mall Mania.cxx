#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int x,y,A[2005][2005],B[2005][2005],ste[2005][2005],dx[6]={1,-1,0,0},dy[6]={0,0,1,-1},out;
vector<int> v[2005];
queue<pair<int,int> > q;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,a,b,T,m;
	while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            return 0;
        memset(B,0,sizeof B);
        memset(ste,0,sizeof ste);
        while(!q.empty())
              q.pop();
        for(i=0;i<=2000;i++)
            for(j=0;j<=2000;j++)
                ste[i][j]=MI;
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&x,&y);
            q.emplace(x,y);
            ste[x][y]=0;
        }
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&x,&y);
            B[x][y]=1;
        }
        out=0;
        while(!q.empty())
        {
            tie(x,y)=q.front();
            q.pop();
            if(B[x][y]==1)
            {
                out=ste[x][y];
                break;
            }
            for(i=0;i<4;i++)
            {
                if(x+dx[i]>=0&&x+dx[i]<=2000&&y+dy[i]>=0&&y+dy[i]<=2000)
                {
                    if(ste[x+dx[i]][y+dy[i]]>=MI)
                    {
                        ste[x+dx[i]][y+dy[i]]=ste[x][y]+1;
                        q.emplace(x+dx[i],y+dy[i]);
                    }
                }
            }
        }
        printf("%d\n",out);
    }
}
