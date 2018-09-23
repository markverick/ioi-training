#include<bits/stdc++.h>
#define MP make_pair
using namespace std;
char in[2];
char maps[1200][1200];
int chk[1200][1200];
queue<pair<int,int> >q;
pair<int,int> ans;
int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    int i,j,k;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%s",in);
            maps[i][j]=in[0];
        }
    }
    q.push(MP(0,0));
    int x=0,y=0;
    chk[0][0]=1;
    ans=MP(9999,9999);
    int fu=-1;
    while(true)
    {
        x=q.front().first;
        y=q.front().second;

        if(fu>=0)
            printf("%d\n%d %d\n",x+y+1,x+1,y+1);
        if(fu>=0&&chk[x][y]!=fu)
        {
            printf("%d\n%d %d\n",x+y+1,x+1,y+1);
            exit(0);
        }
        q.pop();
        if(maps[x][y]=='B')
        {
            if(chk[x+1][y]==0){
                chk[x+1][y]=chk[x][y]+1;
                q.push(MP(x+1,y));
            }
            else{
                //printf("%d\n%d %d\n",x+y+1,x+1,y+1);
                ans=min(ans,MP(y,x+1));
                fu=chk[x][y];
            }
            if(chk[x][y+1]==0){
                chk[x][y+1]=chk[x][y]+1;
                q.push(MP(x,y+1));
            }
            else{
                //printf("%d\n%d %d\n",x+y+1,x+1,y+1);
                ans=min(ans,MP(y+1,x));
                fu=chk[x][y];
            }
        }
        else if(maps[x][y]=='D')
        {
            if(chk[x+1][y]==0){
                chk[x+1][y]=chk[x][y]+1;
                q.push(MP(x+1,y));
            }
            else{
                //printf("%d\n%d %d\n",x+y+1,x+1,y+1);
                ans=min(ans,MP(y,x+1));
                fu=chk[x][y];
            }
        }
        else if(maps[x][y]=='R')
        {
            if(chk[x][y+1]==0){
                chk[x][y+1]=chk[x][y]+1;
                q.push(MP(x,y+1));
            }
            else{
                //printf("%d\n%d %d\n",x+y+1,x+1,y+1);
                ans=min(ans,MP(y+1,x));
                fu=chk[x][y];
            }
        }
    }
    printf("-1\n");
}
