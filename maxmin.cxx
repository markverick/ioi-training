#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int stMax[2135][2135];
int stMin[2135][2135];
int n,m;
int x,y,val,idxX,toAddX;
int x1,x2,y_1,y2;
void setY(int idx,int fst,int lst,int idxY,int fstY,int lstY)
{
    //printf("%d %d %d %d %d %d\n",idx,fst,lst,idxY,fstY,lstY);
    int mid=(fstY+lstY)/2;
    if(fstY==lstY)
    {
        if(fst==lst)
        {
            stMax[idx][idxY]=val;
            stMin[idx][idxY]=val;
        }
        else
        {
            stMax[idx][idxY]=max(stMax[idx*2][idxY],stMax[idx*2+1][idxY]);
            stMin[idx][idxY]=min(stMin[idx*2][idxY],stMin[idx*2+1][idxY]);
        }
        return;
    }
    if(y<=mid)
    {
        setY(idx,fst,lst,idxY*2,fstY,mid);
    }
    else
    {
        setY(idx,fst,lst,idxY*2+1,mid+1,lstY);
    }
    stMax[idx][idxY]=max(stMax[idx][idxY*2],stMax[idx][idxY*2+1]);
    stMin[idx][idxY]=min(stMin[idx][idxY*2],stMin[idx][idxY*2+1]);

}
void setX(int idx,int fst,int lst)
{
    //printf("%d %d %d\n",idx,fst,lst);
    int mid=(fst+lst)/2;
    if(fst!=lst)
    {
        if(fst<=x&&x<=mid)
        {
            setX(idx*2,fst,mid);
        }
        if(mid+1<=x&&x<=lst)
        {
            setX(idx*2+1,mid+1,lst);
        }

    }
    setY(idx,fst,lst,1,1,m);
}
pair<int,int> findY(int idx,int fst,int lst,int idxY,int fstY,int lstY)
{
    int mid=(fstY+lstY)/2;
    if(lstY<y_1||fstY>y2)
    {
        return {0,2000000000};
    }
    if(y_1<=fstY&&y2>=lstY)
    {
        return {stMax[idx][idxY],stMin[idx][idxY]};
    }
    pair<int,int> a,b;
    a=findY(idx,fst,lst,idxY*2,fstY,mid);
    b=findY(idx,fst,lst,idxY*2+1,mid+1,lstY);
    return {max(a.X,b.X),min(a.Y,b.Y)};
}
pair<int,int> findX(int idx,int fst,int lst)
{
   // printf("%d %d %d\n",idx,fst,lst);
    int mid=(fst+lst)/2;
    if(lst<x1||fst>x2)
    {
        return {0,2000000000};
    }
    if(x1<=fst&&x2>=lst)
    {
        return findY(idx,fst,lst,1,1,m);
    }
    pair<int,int>a,b;
    a=findX(idx*2,fst,mid);
    b=findX(idx*2+1,mid+1,lst);

    return {max(a.X,b.X),min(a.Y,b.Y)};
}
int main()
{
    int i,j,k;
    scanf("%d %d",&n,&m);
    //int tmp;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&val);
            //maps[i][j]++;
            x=i;y=j;
            setX(1,1,n);
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
            setX(1,1,n);
        }
        else
        {
            scanf("%d %d %d %d",&x1,&y_1,&x2,&y2);
            pair<int,int> out=findX(1,1,n);
            printf("%d %d\n",out.X,out.Y);
        }
    }
}
