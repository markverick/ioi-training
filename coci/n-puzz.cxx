#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char maps[6][6];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,sum=0;
	for(i=0;i<4;i++)
    {
        scanf("%s",maps[i]);
        for(j=0;j<4;j++)
        {
            if(maps[i][j]!='.')maps[i][j]-='A';
            else maps[i][j]=15;
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(maps[i][j]<15)
                sum+=abs(maps[i][j]/4-i)+abs(maps[i][j]%4-j);
        }
    }
    printf("%d",sum);
}
