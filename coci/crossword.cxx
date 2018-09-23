#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char a[50],b[50];
int hsh[500];
char maps[50][50];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,la,lb,x,y;
    scanf("%s %s",a+1,b+1);
    la=strlen(a+1);
    lb=strlen(b+1);
    for(i=lb;i>=1;i--)
    {
        hsh[b[i]]=i;
    }
    for(i=1;i<=la;i++)
    {
        if(hsh[a[i]])
        {
            x=i;y=hsh[a[i]];
            break;
        }
    }
    for(i=1;i<=lb;i++)
        for(j=1;j<=la;j++)
            maps[i][j]='.';
    for(i=1;i<=la;i++)
        maps[y][i]=a[i];
    for(i=1;i<=lb;i++)
        maps[i][x]=b[i];
    for(i=1;i<=lb;i++)
    {
        printf("%s\n",maps[i]+1);
    }
}
