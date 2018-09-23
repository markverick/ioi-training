#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char maps[12][12],a[55][55];
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,r,c,deg,L=0,R=50;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
    {
        scanf("%s",maps[i]+1);
    }
    for(i=0;i<=50;i++)
        for(j=0;j<=50;j++)
            a[i][j]=' ';
    scanf("%d",&deg);
    while(deg>45)
    {
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                a[i][j]=maps[i][j];
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                maps[j][r-i+1]=a[i][j];
        swap(r,c);
        deg-=90;
    }
    if(deg==45)
    {
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                a[i+j-1][20+j-i]=maps[i][j];
            }
        }
        for(i=1;i<r+c;i++)
        {
            j=20+c;
            while(j>=20+1-r)
            {
                if(a[i][j]!=' ')
                    break;
                a[i][j]=0;
                j--;
            }
        }
        for(i=1;i<r+c;i++)
        {
            printf("%s\n",&a[i][20+1-r]);
        }
    }
    else
    {
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                printf("%c",maps[i][j]);
            }
            printf("\n");
        }
    }
}
