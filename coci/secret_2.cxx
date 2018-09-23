#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[135],t[135];
char mat[135][135];
int main()
{
	int i,j,k,r,c,n;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(r=floor(sqrt(n));r>=1;r--)
    {
        if(n%r==0)
        {
            c=n/r;k=1;
            for(i=1;i<=c;i++)
            {
                for(j=1;j<=r;j++)
                {
                    mat[j][i]=s[k++];
                }
            }
            for(i=1;i<=r;i++)
            {
                for(j=1;j<=c;j++)
                {
                    printf("%c",mat[i][j]);
                }
            }
//            printf("\n!%d %d\n",r,c);
            return 0;
        }
    }
}
