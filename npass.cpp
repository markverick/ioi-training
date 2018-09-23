#include<bits/stdc++.h>
int n;
long long skGrader[1000][12];
unsigned long long fx(int idx,int num) //r[2] = ->, l[3] = <-, u[0] = ^, d[1] = v
{
    if(skGrader[idx][num]>=0)
    {
        return skGrader[idx][num];
    }
    if(idx==n)
    {
        return 1;
    }
    switch (num)
    {
    case 0:
        return skGrader[idx][0] = fx(idx+1,7);
        break;
    case 1:
        return skGrader[idx][1] = fx(idx+1,2)+fx(idx+1,4);
        break;
    case 2:
        return skGrader[idx][2] = fx(idx+1,1)+fx(idx+1,3)+fx(idx+1,5);
        break;
    case 3:
        return skGrader[idx][3] = fx(idx+1,2)+fx(idx+1,6);
        break;
    case 4:
        return skGrader[idx][4] = fx(idx+1,1)+fx(idx+1,5)+fx(idx+1,7);
        break;
    case 5:
        return skGrader[idx][5] = fx(idx+1,2)+fx(idx+1,4)+fx(idx+1,6)+fx(idx+1,8);
        break;
    case 6:
        return skGrader[idx][6] = fx(idx+1,3)+fx(idx+1,5)+fx(idx+1,9);
        break;
    case 7:
        return skGrader[idx][7] = fx(idx+1,4)+fx(idx+1,8)+fx(idx+1,0);
        break;
    case 8:
        return skGrader[idx][8] = fx(idx+1,5)+fx(idx+1,7)+fx(idx+1,9);
        break;
    case 9:
        return skGrader[idx][9] = fx(idx+1,6)+fx(idx+1,8);
        break;
    }
}

int main()
{
    int i,j;
    for(i=0;i<1000;i++)
    {
        for(j=0;j<12;j++)
        {
            skGrader[i][j]=-1;
        }
    }
    unsigned long long sum = 0;
    while(scanf("%d",&n)!=EOF)
    {
        n--;
       for(i=0;i<=9;i++)
       {
            sum+=fx(0,i);

       }
        printf("%llu\n",sum);
        for(i=0;i<1000;i++)
        {
            for(j=0;j<12;j++)
            {
                skGrader[i][j]=-1;
            }
        }
        sum=0;
    }
}
