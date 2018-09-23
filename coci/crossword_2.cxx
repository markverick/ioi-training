#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char str[10][5],hsh[5][5];
int a[8];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,fk;
	for(i=0;i<6;i++)
        scanf("%s",str[i]),a[i]=i;
    do
    {
        memset(hsh,0,sizeof hsh);
        fk=0;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(hsh[i][j]==0||hsh[i][j]==str[a[i]][j])
                    hsh[i][j]=str[a[i]][j];
                else
                {
                    fk=1;break;
                }
            }
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(hsh[j][i]==0||hsh[j][i]==str[a[i+3]][j])
                    hsh[j][i]=str[a[i+3]][j];
                else
                {
                    fk=1;break;
                }
            }
        }
        if(fk==0)
        {
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                    printf("%c",hsh[i][j]);
                printf("\n");
            }
            return 0;
        }
    }
    while(next_permutation(&a[0],&a[6]));
    printf("0");
}
