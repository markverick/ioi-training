#include<bits/stdc++.h>
int n;
int nTile=0;
long long jum[2000][10];
long long omelet(int idx,int shape)
{
    if(idx==0)
    {
        if(shape==1)
            return 1;
        else
            return 0;
    }
    if(idx<0)
        return 0;
    if(jum[idx][shape]>=0)
    {
        return jum[idx][shape];
    }
    switch (shape) //from omelet's note book
    {
    case 1:return jum[idx][shape] = omelet(idx-3,1)+omelet(idx-1,7)+omelet(idx-1,5);break;
    case 2:return jum[idx][shape] = omelet(idx-1,1)+omelet(idx-2,5);break;
    case 3:return jum[idx][shape] = omelet(idx-2,6);break;
    case 4:return jum[idx][shape] = omelet(idx-1,1)+omelet(idx-2,7);break;
    case 5:return jum[idx][shape] = omelet(idx-1,2);break;
    case 6:return jum[idx][shape] = omelet(idx-1,3);break;
    case 7:return jum[idx][shape] = omelet(idx-1,4);break;

    }
    return 0;
}
int main()
{
    int i,j;
    for(i=0;i<2000;i++)for(j=0;j<10;j++)jum[i][j]=-1;
    scanf("%d",&n);
    nTile=3*n/2;
        //for(i=nTile;i>=0;i-=2)omelet(i,1);
    printf("%lld",omelet(nTile,1));
}
