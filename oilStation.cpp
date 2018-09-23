#include<bits/stdc++.h>
int cot=0;
char maps[120][120];
int hash[120][120];
//int stx[10000],sty[10000];
int dfs(int x,int y){
    //printf("%d %d %c\n",x,y,maps[x][y]);
    hash[x][y]++;
    if(maps[x+1][y]=='@'&&hash[x+1][y]==0)dfs(x+1,y);
    if(maps[x-1][y]=='@'&&hash[x-1][y]==0)dfs(x-1,y);
    if(maps[x][y+1]=='@'&&hash[x][y+1]==0)dfs(x,y+1);
    if(maps[x][y-1]=='@'&&hash[x][y-1]==0)dfs(x,y-1);
    if(maps[x+1][y+1]=='@'&&hash[x+1][y+1]==0)dfs(x+1,y+1);
    if(maps[x-1][y-1]=='@'&&hash[x-1][y-1]==0)dfs(x-1,y-1);
    if(maps[x-1][y+1]=='@'&&hash[x-1][y+1]==0)dfs(x-1,y+1);
    if(maps[x+1][y-1]=='@'&&hash[x+1][y-1]==0)dfs(x+1,y-1);
    return 0;

}
int main(){
	int r,c;
	int i,j,k,p,q;
	while(true)
    {
        scanf("%d %d",&r,&c);
        if(r==0)break;
        i=0;j=0;k=0;p=0;q=0;cot=0;memset(hash,0,sizeof hash);memset(maps,0,sizeof maps);
        for(i=0;i<r;i++){
            scanf("%s",maps[i]);
        }
        int idx;
        int x,y;
        int cot=0,max=0;
        cot=0;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(maps[i][j]=='@'&&hash[i][j]==0){
                    dfs(i,j);
                    //printf("\n");
                    cot++;
                }
            }
        }
        printf("%d\n",cot);
    }
}
