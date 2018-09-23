#include<bits/stdc++.h>
int n;
long long skGrader[1000][5];
unsigned long long fx(int idx,int dir) //r[2] = ->, l[3] = <-, u[0] = ^, d[1] = v
{
    if(skGrader[idx][dir]>=0)
    {
        return skGrader[idx][dir];
    }
    if(idx==n)
    {
        return 1;
    }
    switch (dir)
    {
    case 0:
        return skGrader[idx][0] = fx(idx+1,0)+fx(idx+1,1)+fx(idx+1,2);
        break;
    case 1:
        return skGrader[idx][1] = fx(idx+1,0)+fx(idx+1,2);
        break;
    case 2:
        return skGrader[idx][2] = fx(idx+1,0)+fx(idx+1,1);
        break;
    }
}

int main()
{
    int i,j;
    for(i=0;i<1000;i++)
    {
        for(j=0;j<5;j++)
        {
            skGrader[i][j]=-1;
        }
    }
    scanf("%d",&n);
    printf("%llu",fx(0,0));
}
