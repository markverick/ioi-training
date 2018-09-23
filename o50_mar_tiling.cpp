#include<bits/stdc++.h>
using namespace std;
char maps[33][33];
int mat[2135][2135],hsh[33][33],result[2135],state[2135],n;
int dx[6]={1,-1,0,0};
int dy[6]={0,0,1,-1};
void Hash(int a,int b,int c,int d)
{
    hsh[a][b]=1;
    hsh[c][d]=1;
}
int dfs(int idx,int C)
{
    int i;
    result[C]=idx;
    state[idx]=1;
    if(idx==n*n*2+1)
    {
        for(i=0;i<C;i++)
        {
//            printf("%d -> %d\n",result[i],result[i+1]);
            mat[result[i]][result[i+1]]=0;
            mat[result[i+1]][result[i]]=1;
        }
        return 1;
    }
    for(i=0;i<=n*n*2+1;i++)
    {
        if(mat[idx][i]==1&&state[i]==0)
        {
            if(dfs(i,C+1))
                return 1;
        }
    }
    return 0;
}
int main()
{
    int i,j,k,all=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",maps[i]+1);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(maps[i][j]!='#')
                continue;
            all++;
            mat[0][(i-1)*n+j]=1;
            for(k=0;k<4;k++)
            {
                if(maps[i+dx[k]][j+dy[k]]=='#')
                {
                    if((i+j)%2==0)
                        mat[(i-1)*n+j][n*n+(i+dx[k]-1)*n+j+dy[k]]=1;
//                    mat[(i+dx[k]-1)*n+j+dy[k]][n*n+(i-1)*n+j]=1;
                }
            }
            mat[n*n+(i-1)*n+j][n*n*2+1]=1;
        }
    }
//    for(i=0;i<=n*n*2+1;i++)
//    {
//        for(j=0;j<=n*n*2+1;j++)
//        {
//            printf("%d ",mat[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n\n");
    result[0]=0;
    while(dfs(0,1))
    {
        memset(state,0,sizeof state);
    }
//    for(i=0;i<=n*n*2+1;i++)
//    {
//        for(j=0;j<=n*n*2+1;j++)
//        {
//            printf("%d ",mat[i][j]);
//        }
//        printf("\n");
//    }
    int a,b,c,d,fu=0;
    vector<tuple<int,int,int,int> > v;
    for(i=n*n+1;i<=n*n*2;i++)
    {
        for(j=1;j<=n*n;j++)
        {
            if(mat[i][j]==1)
            {
                a=(i-n*n-1)/n+1;b=(i-n*n-1)%n+1;c=(j-1)/n+1;d=(j-1)%n+1;
                if(hsh[a][b]==0&&hsh[c][d]==0)
                {
                    fu+=2;
                    Hash(a,b,c,d);
                    v.emplace_back(a,b,c,d);
                }
            }
        }
    }
    sort(v.begin(),v.end());
    if(fu!=all)
        printf("no solution\n");
    else
    {
        for(i=0;i<v.size();i++)
        {
            tie(a,b,c,d)=v[i];
            printf("%d %d %d %d\n",a,b,c,d);
        }
    }
}
