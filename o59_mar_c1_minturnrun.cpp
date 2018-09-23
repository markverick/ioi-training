#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back;
using namespace std;
int dx[6]={1,-1,0};
int dy[6]={0,0,1};
vector<string> maps;
int r,c,s,dp[3][1000135],tmp[1000135];
priority_queue<pair<int,int> > pq;
int chk(int x,int y)
{
    if(x>=1&&x<=r&&y>=1&&y<=c&&maps[x][y]=='.')
        return 1;
    else
        return 0;
}
int main()
{
    int i,j,k,l;
    cin >> r >> c >> s;
    maps.resize(r+5);
    for(i=1;i<=r;i++)
    {
        cin >> maps[i];
        maps[i]="0"+maps[i];
    }
    for(i=0;i<=1;i++)
    {
        for(j=1;j<=r;j++)
        {
            dp[i][j]=1000000000;
        }
    }
    dp[1][s]=0;
    int col,w,x;
    for(col=1;col<=c;col++)
    {
        for(i=1;i<=r;i++)
        {
            if(chk(i,col)&&dp[col%2][i]<1000000000)
                pq.emplace(-dp[col%2][i],i);
            dp[1-col%2][i]=1000000000;
            tmp[i]=1000000000;
        }
        while(!pq.empty())
        {
            tie(w,x)=pq.top();
            pq.pop();
            w=-w;
            i=x+1;
            while(chk(i,col)&&w+2<tmp[i])
            {
                tmp[i]=w+2;
                i++;
            }
            i=x-1;
            while(chk(i,col)&&w+2<tmp[i])
            {
                tmp[i]=w+2;
                i--;
            }
        }
        for(i=1;i<=r;i++)
        {
            dp[col%2][i]=min(dp[col%2][i],tmp[i]);
        }
//        for(i=1;i<=r;i++)
//        {
//            if(dp[col%2][i]<1000000000)
//                printf("%d ",dp[col%2][i]);
//            else
//                printf("X ");
//        }
//        printf("\n");
//        if(col==c)
//            break;
        for(i=1;i<=r;i++)
        {
            if(chk(i,col+1))
            {
                dp[1-col%2][i]=dp[col%2][i];
            }
//            else
//            {
//                dp[1-col%2][i]=1000000000;
//            }
        }
    }
    int mn=1000000000;
    for(i=1;i<=r;i++)
    {
        mn=min(mn,dp[c%2][i]);
    }
    if(mn==1000000000)
        printf("-1");
    else
        printf("%d",mn);
}

