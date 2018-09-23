#include<bits/stdc++.h>
using namespace std;
int maps[40][40],jum[135][135][135],qs[135][135],x[135],n;
int dp(int fst,int lst,int val)
{
    if(jum[fst][lst][val]>=0)
        return jum[fst][lst][val];
    if(fst==lst)
    {
        if(x[fst]==val)
            return 1;
        else
            return 0;
    }
    int sum=0,i,j,k;
    for(i=fst;i<lst;i++)
        if(maps[qs[fst][i]][qs[i+1][lst]]==val)
            for(j=0;j<n;j++)
                for(k=0;k<n;k++)
                    if(maps[j][k]==val)
                        sum+=dp(fst,i,j)*dp(i+1,lst,k);
    return jum[fst][lst][val]=sum;
}
int main()
{
    int i,j,k,m;
    scanf("%d",&n);
    memset(jum,-1,sizeof jum);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&maps[i][j]);
    scanf("%d",&m);
    for(i=0;i<m;i++)
        scanf("%d",&x[i]);
    for(i=0;i<m;i++)
    {
        qs[i][i]=x[i];
        for(j=i+1;j<m;j++)
            qs[i][j]=maps[qs[i][j-1]][x[j]];
    }
    for(i=0;i<n;i++)
        printf("%d\n",dp(0,m-1,i));
}
