#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int maps[531][531];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,r,c,fs,md,ls,mc=0,Q,L,R;
    while(scanf("%d %d",&r,&c)!=EOF)
    {
        if(r==0&&c==0)
            return 0;
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                scanf("%d",&maps[i][j]);
            }
        }
        scanf("%d",&Q);
        while(Q--)
        {
            scanf("%d %d",&L,&R);
            mc=0;
            for(i=1;i<=r;i++)
            {
                j=lower_bound(&maps[i][1],&maps[i][c+1],L)-&maps[i][0];
                fs=0;ls=min(r,c);
                while(fs<=ls)
                {
                    md=(fs+ls)/2;
                    if(i+md-1<=r&&j+md-1<=c&&maps[i+md-1][j+md-1]<=R)
                    {
                        mc=max(mc,md);
                        fs=md+1;
                    }
                    else
                        ls=md-1;
                }
            }
            printf("%d\n",mc);
        }
        printf("-\n");
    }
}
