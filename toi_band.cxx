#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
pair<int,int> p[5500];
int hsh[1200][1200];
int main()
{
    int n,m,i,j,k,c5=0,c6=0,cot=0,sum=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&p[i].X,&p[i].Y);
        hsh[p[i].X][p[i].Y]=1;
        hsh[p[i].Y][p[i].X]=1;
    }
    sort(&p[1],&p[m+1]);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(p[i].X!=p[j].X&&p[i].X!=p[j].Y&&p[i].Y!=p[j].X&&p[i].Y!=p[j].Y)
            {
                cot=2;
                if(hsh[p[i].X][p[j].X])cot++;
                if(hsh[p[i].X][p[j].Y])cot++;
                if(hsh[p[i].Y][p[j].X])cot++;
                if(hsh[p[i].Y][p[j].Y])cot++;
                if(cot==6)c6++;
                if(cot==5)c5++;
                if(cot>=5)sum++;
            }
        }
    }
    printf("%d",(sum-c6*2/3-c5/2)/2);
}
