#include<bits/stdc++.h>
int maps[8][8];
int chieng[8][8];
char str[8];
int result[8][8];
int rX[30];
// int rY[6];
int cot=0;
int outX[50];
int outY[50];
int idx=0,idx2=0;
int fk=1;
void print(void)
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%d",chieng[i][j]);
        }
        printf("\n");
    }
    printf("====\n");
}
void toggle(int x,int y)
{
    chieng[x][y]=1-chieng[x][y];
    if(x+1<5)
        chieng[x+1][y]=1-chieng[x+1][y];
    if(y+1<5)
        chieng[x][y+1]=1-chieng[x][y+1];
    if(x-1>=0)
        chieng[x-1][y]=1-chieng[x-1][y];
    if(y-1>=0)
        chieng[x][y-1]=1-chieng[x][y-1];

}
void genx(int x)
{
    if(fk==0)return;
    int i,j,k;
    if(x==25)
    {
        idx=0;
        /*for(i=0;i<16;i++)
        {
            printf("%d",rX[i]);
        }*/
        //printf("\n");
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {

                result[i][j]=rX[i*5+j];
                if(result[i][j]==1)
                {

                    toggle(i,j);
                    outX[idx]=i;
                    outY[idx++]=j;
                    //print();
                    //printf("i=%d, j=%d\n",i,j);
                }
                //printf("%d",result[i][j]);
            }
        }
        int fu=0;
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(chieng[i][j]==0)
                {
                    fu=1;
                }
            }
        }
        if(fu==0)
        {

            fk=0;
            idx2=idx;
            for(int k=0;k<idx2;k++)
            {
                printf("%d %d\n",outX[k]+1,outY[k]+1);
            }
            exit (0);
            return;
        }
        memset(outX,0,sizeof outX);
        memset(outY,0,sizeof outY);
        for(i=0;i<5;i++)
            for(j=0;j<5;j++)
                chieng[i][j]=maps[i][j];
        //cot++;
       // printf("\n");
        return;
    }
    rX[x]=0;
    genx(x+1);
    rX[x]=1;
    genx(x+1);
}
int main()
{
    int i,j,k,l;
    for(i=0;i<5;i++)
    {
        scanf("%s",str);
        for(j=0;j<5;j++)
        {
            maps[i][j]=str[j]-'0';
            chieng[i][j]=str[j]-'0';
        }
    }
    genx(0);
    for(k=0;k<idx2;k++)
    {
        printf("%d %d\n",outX[k]+1,outY[k]+1);
    }
   // printf("=%d=",cot);
    /*for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            for(j=0;j)
        }
    }*/

}
