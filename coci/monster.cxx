#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int dx[6]={0,0,1,1},dy[6]={0,1,0,1};
char maps[55][55];
int hsh[6];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
    int i,j,k,r,c,fk,cot,sum=0;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
    {
        scanf("%s",maps[i]+1);
    }
    for(i=1;i<r;i++)
    {
        for(j=1;j<c;j++)
        {
            fk=0;cot=0;
            for(k=0;k<4;k++)
            {
                if(maps[i+dx[k]][j+dy[k]]=='#')
                {
                    fk=1;
                    break;
                }
                else if(maps[i+dx[k]][j+dy[k]]=='X')
                    cot++;
            }
            if(fk)continue;
            hsh[cot]++;
            sum++;
        }
    }
//    printf("%d\n",sum);
    for(i=0;i<=4;i++)
        printf("%d\n",hsh[i]);
}
