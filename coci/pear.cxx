#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int r[100135],c[100135],turn[205][205][8][5],days[205][205][8][5];
tuple<int,int,int,int> nxt[205][205][8][5];
char str[100135][10];
int maps[222][222],dx[6]={0,1,0,-1},dy[6]={1,0,-1,0};
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int sturn,sday;
	int i,j,k,n,T,m,x,y,d,day,xx,yy,dd,dday,D;
	scanf("%d %d %d",&n,&T,&m);
	memset(maps,-1,sizeof maps);
	for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            maps[i][j]=0;
	for(i=1;i<=m;i++)
    {
        scanf("%d %d %s",&r[i],&c[i],str[i]);
        maps[r[i]][c[i]]=i;
    }
    x=1;y=1;day=0;d=0;
    turn[x][y][day][d]=0;
    days[x][y][day][d]=0;
    D=1;
    while(135)
    {
        k=maps[x+dx[d]][y+dy[d]];
        xx=x;yy=y;dday=day;dd=d;
        day=(day+1)%7;
        if(maps[x+dx[d]][y+dy[d]]==0)
        {
            x+=dx[d];
            y+=dy[d];
        }
        else if(k==-1)
        {
            d=(d+2)%4;
            D--;
            day=(day+6)%7;
        }
        else
        {
            if(str[k][day]=='R')
            {
                x+=dx[d];
                y+=dy[d];
                d=(d+1)%4;
            }
            else if(str[k][day]=='L')
            {
                x+=dx[d];
                y+=dy[d];
                d=(d+4-1)%4;
            }
            else
            {
                x+=dx[d];
                y+=dy[d];
            }
        }
        nxt[xx][yy][dday][dd]=MT(x,y,day,d);
        if(get<0>(nxt[x][y][day][d]))
        {
            if(dd!=d)
                sturn=turn[xx][yy][dday][dd]+1;
            else
                sturn=turn[xx][yy][dday][dd];
            sday=D++;
            break;
        }
        if(dd!=d)
            turn[x][y][day][d]=turn[xx][yy][dday][dd]+1;
        else
            turn[x][y][day][d]=turn[xx][yy][dday][dd];
        days[x][y][day][d]=D++;
//        printf("[%d][%d] in %d th day at %d direction. Using %d turn.\n",x,y,day,d,turn[x][y][day][d]);
//        printf("%d %d %d %d\n",x,y,day,d);
    }
//    printf("1 Cycle = [%d][%d] %d - - - > [%d][%d] %d\n - Using %d Days\n",x,y,turn[x][y][day][d],xx,yy,turn[xx][yy][dday][dd],days[xx][yy][dday][dd]-days[x][y][day][d]);
    int cyc=sturn-turn[x][y][day][d],dcyc=sday-days[x][y][day][d];
//    printf("%d %d\n",sturn,sday);
    if(T<sturn)
    {
        if(T==0)
        {
            printf("0");
            return 0;
        }
        x=1;y=1;day=0;d=0;
        while(135)
        {
            tie(x,y,day,d)=nxt[x][y][day][d];
            if(turn[x][y][day][d]>=T)
                break;
        }
        printf("%d",days[x][y][day][d]);
        return 0;
    }
    int st=days[x][y][day][d],stu=turn[x][y][day][d];
    k=T-turn[x][y][day][d];
    long long sum=days[x][y][day][d]+(long long)(k/cyc)*dcyc;
    if(k%cyc==0)
    {
        printf("%lld",sum);
        return 0;
    }
    while(135)
    {
        tie(x,y,day,d)=nxt[x][y][day][d];
        if(turn[x][y][day][d]-stu>=k%cyc)
            break;
    }
    sum+=days[x][y][day][d]-st;
    printf("%lld",sum);
}
