#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char str[135];
char maps[135][135];
int state[135][135];
int dx[10]={1,1,1,0,0,-1,-1,-1};
int dy[10]={-1,0,1,-1,1,-1,0,1};
int dfs(int x,int y)
{
    if(maps[x][y]!='W')return 0;
    state[x][y]=1;
    int sum=1,i;
    for(i=0;i<8;i++)
    {
        if(maps[x+dx[i]][y+dy[i]]!='W'||state[x+dx[i]][y+dy[i]])
            continue;
        sum+=dfs(x+dx[i],y+dy[i]);
    }
    return sum;
}
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int T,r,c,i,j,k,a,b;
	bool fk;
	gets(str);
    sscanf(str,"%d",&T);
    gets(str);
    while(T--)
    {
        r=0;
        while(gets(str))
        {
            if(str[0]>='0'&&str[0]<='9')
                break;
            r++;
            strcpy(maps[r]+1,str);
        }
        c=strlen(maps[1]+1);
//        for(i=1;i<=r;i++)
//        {
//            for(j=1;j<=c;j++)
//                printf("%c",maps[i][j]);
//            printf("\n");
//        }
        sscanf(str,"%d %d",&a,&b);
        while(135)
        {
            fk=gets(str);
            memset(state,0,sizeof state);
            printf("%d\n",dfs(a,b));
            if(fk==0||strlen(str)==0)
                break;
            sscanf(str,"%d %d",&a,&b);
        }
        if(T)
            printf("\n");
    }

}
