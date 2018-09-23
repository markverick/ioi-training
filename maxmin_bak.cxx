#include<bits/stdc++.h>
using namespace std;
int maps[3000][3000];
int stMax[3000][3000];
int stMin[3000][3000];
int n,m;
int x,y,val,idxX,toAddX;
int x1,x2,y1,y2;
void addMaxY(int idx,int fst,int lst);
void addMaxX(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;

    //printf("  addMaxX : idx [%d] =%d %d\n",idx,fst,lst);
    if(fst==lst)
    {
        idxX=idx;
        addMaxY(1,1,m);
        return;
    }
    if(x<=mid)
    {
        addMaxX(idx*2,fst,mid);
    }
    else
    {
        addMaxX(idx*2+1,mid+1,lst);
    }
    idxX=idx;
    addMaxY(1,1,m);

}
void addMaxY(int idx,int fst,int lst)
{
    //printf("%d %d\n",idxX,idx);
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        stMax[idxX][idx]=val;
        return;
    }
    if(y<=mid)
    {
        addMaxY(idx*2,fst,mid);
    }
    else
    {
        addMaxY(idx*2+1,mid+1,lst);
    }
    stMax[idxX][idx]=max(stMax[idxX][idx*2],stMax[idxX][idx*2+1]);
}
int findMaxY(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(y2<fst||y1>lst)
    {
        return 0;
    }
    if(fst>=y1&&lst<=y2)
    {
        return stMax[idxX][idx];
    }
    return findMaxY(idx*2,fst,mid)+findMaxY(idx*2+1,mid+1,lst);
}
int findMaxX(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(x2<fst||x1>lst)
    {
        return 0;
    }
    if(fst>=x1&&lst<=x2)
    {
        idxX=idx;
        return findMaxY(1,1,m);
    }
    return findMaxX(idx*2,fst,mid)+findMaxX(idx*2+1,mid+1,lst);
}
int main()
{
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&maps[i][j]);
            x=i;y=j;val=maps[i][j];
            addMaxX(1,1,n);
        }
    }
    int T;
    char Q[3];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",Q);
        if(Q[0]=='c')
        {
            scanf("%d %d %d",&x,&y,&val);
            addMaxX(1,1,n);
        }
        else
        {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            int Max=findMaxX(1,1,n);
            printf("%d %d\n",Max,Min);
        }
    }
}
