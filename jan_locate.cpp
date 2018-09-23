#include<bits/stdc++.h>
int maps[50][50];
int main()
{
    //freopen("output.txt","w",stdout);
    int t,i,j,k,r,c,val=0,rhi=0,rx,ry,chi=0,cx,cy;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {

        memset(maps,0,sizeof maps);
        val=0;rhi=0;chi=0;cx=0;cy=0;rx=0;ry=0;
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                scanf("%d",&maps[i][j]);
               // val+=maps[i][j];
                if(j<=0)
                    continue;
                    val=maps[i][j]+maps[i][j-1];

                if(val>rhi&&abs(maps[i][j]-maps[i][j-1])<=10)
                {
                    rhi=val;    rx=i;   ry=j-1;
                }

            }
        }
        for(j=0;j<c;j++)
        {
            val=0;
            for(i=1;i<r;i++)
            {
                if(i<=0)
                    continue;
                val = maps[i][j]+maps[i-1][j];
                //if(i==5&&j==8)printf("%d",val);
                if(val>chi&&abs(maps[i][j]-maps[i-1][j])<=10)
                {
                   // printf("%d %d = %d %d\n",i,j,maps[i][j],maps[i-1][j]);
                    chi=val;    cx=i-1;   cy=j;
                }
            }
        }
        rx++;ry++;cx++;cy++;
        if(rhi>chi)
        {
            printf("%d %d\n",rx,ry);
        }
        else if(chi>rhi)
        {
            printf("%d %d\n",cx,cy);
        }
        else
        {
            //printf("%d %d\n",chi,rhi);
            if(rx>cx)
            {
                printf("%d %d\n",cx,cy);
            }
            else if(cx>rx)
            {
                printf("%d %d\n",rx,ry);
            }
            else
            {
                if(cy>ry)
                {
                    printf("%d %d\n",rx,ry);
                }
                else
                {
                    printf("%d %d\n",cx,cy);
                }

            }
        }
    }
}
