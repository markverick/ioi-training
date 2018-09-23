#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back
using namespace std;
bool state[102][102][32800];//[32768]
char maps[105][105];
int dx[6]={1,-1,0,0};
int dy[6]={0,0,1,-1};
queue<tuple<int,int,int,int> > q;
int r,c;
int hsh[17];
bool chk(int x,int y)
{
    if(x>=1&&x<=r&&y>=1&&y<=c&&maps[x][y]!='#')
    {
        if(maps[x][y]>='A'&&maps[x][y]<'Z')
        {
//            printf("!%d\n",hsh[0]);
//            printf("%d %d\n",maps[x][y]-'A',hsh[maps[x][y]-'A']);
            if(hsh[maps[x][y]-'A'])
            {
//                printf("YEAH!!\n");
                return 1;
            }
            return 0;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int i,j,k,n,a,b,x,y,bit,walk;
    scanf("%d %d %d",&r,&c,&n);
    for(i=1;i<=r;i++)
    {
        scanf("%s",maps[i]+1);
        for(j=1;j<=c;j++)
        {
            if(maps[i][j]=='z')
                a=i,b=j;
        }
    }
    q.emplace(a,b,0,0);
    state[a][b][0]=1;
    char tmp;
    int mn=1000000000;
    while(!q.empty())
    {
        tie(x,y,bit,walk)=q.front();
        q.pop();
//        printf("%d %d %d %d\n",x,y,bit,walk);
        if(maps[x][y]=='Z')
        {
            mn=min(mn,walk);
        }
        memset(hsh,0,sizeof hsh);
        a=bit;
        i=0;
        while(a>0)
        {
            hsh[i]=a%2;
            i++;
            a/=2;
        }
//        printf("%d %d %d %d %d\n",x,y,bit,walk,hsh[0]);
        for(i=0;i<4;i++)
        {
            if(chk(x+dx[i],y+dy[i])==0)
                continue;
//            printf("%d %d -> %d %d\n",x,y,x+dx[i],y+dy[i]);
            tmp=maps[x+dx[i]][y+dy[i]];
            if(tmp>='a'&&tmp<'z')
            {
                if(state[x+dx[i]][y+dy[i]][bit|(1<<(tmp-'a'))])
                    continue;
                state[x+dx[i]][y+dy[i]][bit|(1<<(tmp-'a'))]=1;
                q.emplace(x+dx[i],y+dy[i],bit|(1<<(tmp-'a')),walk+1);

            }
            else
            {
                if(state[x+dx[i]][y+dy[i]][bit])
                    continue;
                state[x+dx[i]][y+dy[i]][bit]=1;
                q.emplace(x+dx[i],y+dy[i],bit,walk+1);
            }
        }
    }
    if(mn==1000000000)
        printf("-1");
    else
        printf("%d",mn);
}
