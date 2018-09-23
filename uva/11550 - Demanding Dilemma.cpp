#include<bits/stdc++.h>
int mat[50][50];
int main()
{
    int t,i,j,k,l,cot=0,chk=0,r,c,con=0;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                scanf("%d",&mat[i][j]);
            }
        }
        for(j=0;j<c;j++)
        {
            cot=0;
            for(i=0;i<r;i++)
            {
                if(mat[i][j]==1)
                    cot++;
            }
            if(cot!=2)
                chk=1;
        }
        for(i=0;i<r-1;i++)
        {
            for(l=i+1;l<r;l++)
            {
                con=0;
                for(j=0;j<c;j++)
                {
                    if(mat[i][j]==1&&mat[l][j]==1)
                        con++;
                }
                if(con>1)
                {
                    chk=1;
                }
            }

        }
        if(chk==0)
            printf("Yes\n");
        else
            printf("No\n");
        memset(mat,0,sizeof mat);chk=0;cot=0;
    }
}
