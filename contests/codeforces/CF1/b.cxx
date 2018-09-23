#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[1135][1135];
int n[1135],m[1135],qs[1135][1135];
int main()
{
    int i,j,k,r,c,x,y,a,b,C,D,sum=0;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
    {
        scanf("%s",s[i]+1);
        for(j=1;j<=c;j++)
        {
            if(s[i][j]=='*')
                qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+1,sum++;
            else
                qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    int f=0;
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(s[i][j]=='*')
            {
                if(sum==qs[i][c]-qs[i-1][c]+qs[r][j]-qs[r][j-1]-1)
                {
                    f=1;x=i;y=j;
                }
            }
            else
            {
                if(sum==qs[i][c]-qs[i-1][c]+qs[r][j]-qs[r][j-1])
                {
                    f=1;x=i;y=j;
                }
            }
        }
    }
    if(f==1)
        printf("YES\n%d %d",x,y);
    else
        printf("NO\n");

}
