#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
int n,m,dx[6]={1,-1,0,0},dy[6]={0,0,-1,1};
int isChk[9][9];
bool maps[9][9];
vector<int> cx,cy,cn;
inline int isFree(int x,int y)
{
    if(x==0&&y==2)
        return 1;
    if(x>=1&&x<=n&&y>=1&&y<=m&&!maps[x][y])
        return 1;
    else
        return 0;
}
inline int nextchk(int num)
{
    for(int i=0;i<4;i++)
    {
        if(cn[i]>num)
        {
            return i;
            break;
        }
    }
}
//int nearchk(int x,int y)
//{
//    int mn=1000000000,i;
//    for(i=0;i<3;i++)
//    {
//        mn=min(mn,abs(x-cx[i])+abs(y-cy[i]));
//    }
//    return mn;
//}
//int numreq(int num)
//{
//    int i;
//    for(i=0;i<4;i++)
//    {
//        if(cn[i]>num)
//        {
//            return cn[i];
//        }
//    }
//}
inline int freecot(int x,int y)
{
    int cot=0,i;
    for(i=0;i<4;i++)
    {
        if(isFree(x+dx[i],y+dy[i]))
            cot++;
    }
//    if(x==1&&y==2)
//        cot++;
    return cot;
}
inline int dfs(int x,int y,int num)
{
    int i,j;
//    printf("%d %d %d\n",x,y,num);
//    for(i=1;i<=n;i++)
//    {
//        for(j=1;j<=m;j++)
//        {
//            printf("%d ",maps[i][j]);
//        }
//        printf("\n");
//    }
    if(x==1&&y==2)
    {
        if(num==n*m)
            return 1;
        else
            return 0;
    }
    if(isChk[x][y])
    {
        if(num!=isChk[x][y])
            return 0;
    }
    if(!isChk[x][y])
    {
        if(num==n*m/4||num==n*m/2||num==n*m*3/4)
            return 0;
    }
//    if(num==17)
//    {
//        printf("HELLO\n");
//    }
    int nx=nextchk(num);
    if(num+abs(cx[nx]-x)+abs(cy[nx]-y)>cn[nx])
        return 0;
    if(isFree(x+1,y)&&isFree(x-1,y)&&!isFree(x,y+1)&&!isFree(x,y-1))
        return 0;
    if(!isFree(x+1,y)&&!isFree(x-1,y)&&isFree(x,y+1)&&isFree(x,y-1))
        return 0;
    int sum=0,cot=0,fc,go;
    for(i=0;i<4;i++)
    {
        if(!isFree(x+dx[i],y+dy[i]))
            continue;
        fc=freecot(x+dx[i],y+dy[i]);
        if(fc==1)
            cot++,go=i;
    }
    if(cot>1)
        return 0;
    else if(cot==1)
    {
        maps[x+dx[go]][y+dy[go]]=1;
        sum+=dfs(x+dx[go],y+dy[go],num+1);
        maps[x+dx[go]][y+dy[go]]=0;
    }
    else
    {
        for(i=0;i<4;i++)
        {
            if(isFree(x+dx[i],y+dy[i])==0)
                continue;
            maps[x+dx[i]][y+dy[i]]=1;
            sum+=dfs(x+dx[i],y+dy[i],num+1);
            maps[x+dx[i]][y+dy[i]]=0;
        }
    }
    return sum;
}
int main()
{
    int i,j,k,a,b,T=0;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        T++;
        if(n==0&&m==0)
            return 0;
        cx.clear();cy.clear();cn.clear();
        memset(isChk,0,sizeof isChk);
        memset(maps,0,sizeof maps);
        cn.emplace_back(n*m/4);
        cn.emplace_back(n*m/2);
        cn.emplace_back(n*m*3/4);
        cn.emplace_back(n*m);
        for(i=1;i<=3;i++)
        {
            scanf("%d %d",&a,&b);
            a++;b++;
            cx.emplace_back(a);
            cy.emplace_back(b);
            if(i==1)
                isChk[a][b]=n*m/4;
            else if(i==2)
                isChk[a][b]=n*m/2;
            else
                isChk[a][b]=n*m*3/4;
        }
        cx.emplace_back(1);
        cy.emplace_back(2);
        maps[1][1]=1;
        printf("Case %d: %d\n",T,dfs(1,1,1));
    }
}
