#include<bits/stdc++.h>
#define mp(x,y) make_pair(x,y)
using namespace std;

queue<pair<int,int> > q;
char str[150];
char maps[150][150];
int chk[150][150];
int n,m,x,y,cot=0;
    int i,j,k;
void nq(int dist,int i,int j) //enqueue==nq :)
{
    //printf("%d %d %d %d %d %d\n",maps[i][j]=='.',i>=1,i<=n,j>=1,j<=m,(chk[i][j]==0));
    //)
    if(maps[i][j]=='C'||(maps[i][j]=='.'&&i>=1&&i<=n&&j>=1&&j<=m&&(chk[i][j]==0)))
    {
        //printf("wyte");
        q.push(mp(i,j));
        chk[i][j]=dist+1;
    }


}
int main()
{

    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%s",str);
        for(j=1;j<=m;j++)
        {
            maps[i][j]=str[j-1];
            if(maps[i][j]=='B')
            {
                q.push(mp(i,j));
                chk[i][j]=0;
            }

        }
    }
    /*for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
        {
            printf("%c ",maps[i][j]);
        }
        printf("\n");
    }*/
    while(!q.empty())
    {
        x=q.front().first;y=q.front().second;
        q.pop();
        //printf("%d %d\n",x,y);
        k=chk[x][y];
        if(maps[x][y]=='C')
        {
            printf("%d",chk[x][y]);
            break;
        }
        nq(k,x+1,y);nq(k,x-1,y);nq(k,x,y+1);nq(k,x,y-1);

        //cot++;
    }
}
