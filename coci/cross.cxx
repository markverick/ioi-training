#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char maps[12][12];
int hsh[12][12];
int co[12][12];
int num[5][5][12];
int row[12][12];
int col[12][12];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
    int i,j,k,I,J,err=1;
    for(i=0;i<9;i++)
    {
        scanf("%s",maps[i]);
        for(j=0;j<9;j++)
        {
            if(maps[i][j]!='.')
                num[i/3][j/3][maps[i][j]-'0']++;
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            for(k=1;k<=9;k++)
                if(num[i][j][k]>1)
                {
                    printf("ERROR");
                    return 0;
                }
        }
    }
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(maps[i][j]!='.')
                row[i][maps[i][j]-'0']++,col[j][maps[i][j]-'0']++;
        }
    }
    for(k=1;k<=9;k++)
    {
        for(i=0;i<9;i++)
        {
            if(row[i][k]>1||col[i][k]>1)
            {
                printf("ERROR");
                return 0;
            }
        }
    }
    int fk=1;
    while(fk==1)
    {
        fk=0;
        for(k=1;k<=9;k++)
        {
            memset(hsh,0,sizeof hsh);
            memset(co,0,sizeof co);
            for(i=0;i<9;i++)
            {
                for(j=0;j<9;j++)
                {
                    if(maps[i][j]=='0'+k)
                    {
//                        printf("%d !\n",k);
                        for(I=0;I<9;I++)
                            hsh[I][j]=1,hsh[i][I]=1;
                    }
                }
            }
            for(i=0;i<9;i++)
            {
                for(j=0;j<9;j++)
                {
                    if(hsh[i][j]==0&&maps[i][j]=='.')
                        co[i/3][j/3]++;
                }
            }
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {
//                    printf("%d ",co[i][j]);
                    if(num[i][j][k])
                        continue;
                    if(co[i][j]==1)
                    {
                        for(I=0;I<3;I++)
                        {
                            for(J=0;J<3;J++)
                            {
                                if(hsh[i*3+I][j*3+J]==0&&maps[i*3+I][j*3+J]=='.')
                                {
                                    num[i][j][k]++;//                                    printf("[%d][%d] <- %d ! %d\n",i*3+I,j*3+J,k,co[i][j]);

                                    row[i*3+I][k]++;
                                    col[j*3+J][k]++;
                                    if(num[i][j][k]>1||row[i*3+I][k]>1||col[j*3+J][k]>1)
                                    {
                                        printf("ERROR");
                                        return 0;
                                    }
                                    err=0;
                                    maps[i*3+I][j*3+J]='0'+k;
                                    fk=1;
                                }
                            }
                        }
                    }
                    else if(co[i][j]==0)
                    {
                        printf("ERROR");
                        return 0;
                    }
                }
//                printf("\n");
            }
        }
    }
    if(err)
    {
        printf("ERROR");
        return 0;
    }
    for(i=0;i<9;i++)
        printf("%s\n",maps[i]);
}
