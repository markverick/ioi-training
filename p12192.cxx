#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int maps[600][600];
//vector<pair<int,int> > go;
int n,m,a,b;
inline int bs(int x,int y)
{
    int fst=0,mid,lst=min(n,m),mc=0;
    while(fst<=lst)
    {
        mid=(fst+lst)/2;
        if(x-mid>=1&&y-mid>=1&&maps[x-mid][y-mid]>=a)
        {
            mc=max(mc,mid+1);
            fst=mid+1;
        }
        else
        {
            lst=mid-1;
        }
    }
    return mc;
}
int main()
{
    int i,j,k,q,Q,x,y;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
        {
            return 0;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%d",&maps[i][j]);
            }
        }
        int mc=0;
        scanf("%d",&Q);
        for(q=1;q<=Q;q++)
        {
            //go.clear();
            scanf("%d %d",&a,&b);
            int fu=0;mc=0;
            x=1;y=m;
            while(y>=1)
            {
                if(maps[x][y]<=b&&maps[x][y]>=a)
                    mc=max(mc,bs(x,y));
                if(x+1<=n&&maps[x+1][y]<=b)
                {
                    x++;
                }
                else
                {
                    y--;
                }
            }
            printf("%d\n",mc);
        }
        printf("-\n");
    }

}
