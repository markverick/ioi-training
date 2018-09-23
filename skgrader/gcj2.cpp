#include<bits/stdc++.h>
#define MP make_pair
#define MQ(a,b,c,d) make_pair(make_pair(a,b),make_pair(c,d))
#define PB push_back
#define X first
#define Y second
using namespace std;
char maps[12000][12000];
map<pair<pair<int,int>,pair<int,int> >,char > chk;
int main()
{
    //freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,t,i,j,k,r,c,n;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        chk.clear();
        memset(maps,0,sizeof maps);
        scanf("%d %d %d",&r,&c,&n);
        if(n==0)
        {
            printf("Case #%d: 0\n",t);
            continue;
        }
        int room=r*c;
        int ii=0;
        int sum=0;
        int fu=0;
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                if((j+ii)%2)
                    maps[i][j]='0';
                else
                {
                    maps[i][j]='1';
                    sum++;
                    if(sum==n)
                    {
                        fu=1;
                        break;
                    }
                }
            }
            if(fu==1)
                break;
            ii=1-ii;
        }


        if(fu==0&&maps[1][1]=='0')
        {
            maps[1][1]='1';
            sum++;
            if(sum==n)
                fu=1;
        }
        if(fu==0&&maps[1][c]=='0')
        {
            maps[1][c]='1';
            sum++;
            if(sum==n)
                fu=1;
        }
        if(fu==0&&maps[r][1]=='0')
        {
            maps[r][1]='1';
            sum++;
            if(sum==n)
                fu=1;
        }
        if(fu==0&&maps[r][c]=='0')
        {
            maps[r][c]='1';
            sum++;
            if(sum==n)
                fu=1;
        }
        for(i=1;i<=r;i++)
        {
            if(fu==0&&maps[1][i]=='0')
            {
                maps[1][i]='1';
                sum++;
                if(sum==n)
                fu=1;
            }
            if(fu==1)break;
            if(fu==0&&maps[r][i]=='0')
            {
                maps[r][i]='1';
                sum++;
                if(sum==n)
                fu=1;
            }
            if(fu==1)break;
            if(fu==0&&maps[i][1]=='0')
            {
                maps[i][1]='1';
                sum++;
                if(sum==n)
                fu=1;
            }
            if(fu==1)break;
            if(fu==0&&maps[i][c]=='0')
            {
                maps[i][c]='1';
                sum++;
                if(sum==n)
                fu=1;
            }
            if(fu==1)break;
        }
        for(i=2;i<r;i++)
        {
            for(j=2;j<c;j++)
            {
                if(fu==0&&maps[i][j]=='0')
                {
                    maps[i][j]=='1';
                    if(sum==n){
                    fu=1;
                    break;
                    }
                }
            }
            if(fu==1)
                break;
        }
        int s=0;
        /*for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                printf("%c",maps[i][j]);
            }
            printf("\n");
        }*/
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                if(maps[i][j]=='1')
                {
                    if(maps[i+1][j]=='1'&&chk[MQ(i,j,i+1,j)]==0){
                        chk[MQ(i,j,i+1,j)]=1;
                        chk[MQ(i+1,j,i,j)]=1;
                        s++;
                    }
                    if(maps[i-1][j]=='1'&&chk[MQ(i,j,i-1,j)]==0){
                        chk[MQ(i,j,i-1,j)]=1;
                        chk[MQ(i-1,j,i,j)]=1;
                        s++;
                    }
                    if(maps[i][j+1]=='1'&&chk[MQ(i,j,i,j+1)]==0){
                        chk[MQ(i,j+1,i,j)]=1;
                        chk[MQ(i,j,i,j+1)]=1;
                        s++;
                    }
                    if(maps[i][j-1]=='1'&&chk[MQ(i,j,i,j-1)]==0){
                        chk[MQ(i,j-1,i,j)]=1;
                        chk[MQ(i,j,i,j-1)]=1;
                        s++;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",t,s);
    }
}

