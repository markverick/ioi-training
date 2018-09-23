#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char maps[531][531];
int d[531][531],state[531][531];
int dx[6]={1,-1,0,0};
int dy[6]={0,-0,1,-1};
queue<tuple<int,int,int> > q;
int fst,mid,lst,r,c;
void dfs(int x,int y)
{
    int i;
    state[x][y]=1;
    for(i=0;i<4;i++)
    {
        if(x+dx[i]>=1&&x+dx[i]<=r&&y+dy[i]>=1&&y+dy[i]<=c)
        {
            if(state[x+dx[i]][y+dy[i]])
                continue;
            if(d[x+dx[i]][y+dy[i]]>=mid)
                dfs(x+dx[i],y+dy[i]);
        }
    }
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,x,y,w;
	pair<int,int> st,ed;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
    {
        scanf("%s",maps[i]+1);
        for(j=1;j<=c;j++)
        {
            switch(maps[i][j])
            {
            case 'V':
                st=MP(i,j);break;
            case 'J':
                ed=MP(i,j);break;
            case '+':
                d[i][j]=1;
                q.emplace(i,j,1);
            }
        }
    }
    while(!q.empty())
    {
        tie(x,y,w)=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            if(x+dx[i]>=1&&x+dx[i]<=r&&y+dy[i]>=1&&y+dy[i]<=c)
            {
                if(d[x+dx[i]][y+dy[i]])
                    continue;
                d[x+dx[i]][y+dy[i]]=w+1;
                q.emplace(x+dx[i],y+dy[i],w+1);
            }
        }
    }
//    for(i=1;i<=r;i++)
//    {
//        for(j=1;j<=c;j++)
//        {
//            printf("%d",d[i][j]);
//        }
//        printf("\n");
//    }
    fst=0;mid;lst=r*c+1;
    int mc=0;
    while(fst<=lst)
    {
        mid=(fst+lst)/2;
        memset(state,0,sizeof state);
        if(d[st.X][st.Y]>=mid)
            dfs(st.X,st.Y);
        if(state[ed.X][ed.Y])
        {
            mc=max(mc,mid);
            fst=mid+1;
        }
        else
        {
            lst=mid-1;
        }
    }
    printf("%d",mc-1);
}
