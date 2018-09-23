#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[555][555];
int hsh[8];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,r,c,sum;
	scanf("%d",&r,&c);
	scanf("%*s");
	for(i=1;i<=r;i++)
    {
        for(j=1;j<=5;j++)
        {
            scanf("%s",s[j]);
        }
        for(j=1;j<=c;j+=5)
        {
            sum=0;
            for(k=1;k<=5;k++)
            {
                if(s[k][j]=='*')
                    sum++;
            }
            hsh[sum]++;
        }
    }
    for(i=0;i<5;i++)
        printf("%d ",hsh[i]);
}
