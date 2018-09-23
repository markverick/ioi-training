#include<bits/stdc++.h>
int n,x=0,y=0;
char maps[150][150];
int chk[150][150];
int main()
{
    int i,j,k,cot=0;
    int t,fk=0;
    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        memset(maps,0,sizeof maps);
        memset(chk,0,sizeof chk);
        cot=0;x=0;y=0;fk=0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%s",maps[j]);
        }
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                fk=0;
                x=0;y=0;
                if(chk[j][k]==0)
                {


                    if(maps[j][k]=='x')
                    {
                        //printf("%d %d = %c\n",j,k,maps[j][k]);
                        cot++;
                        while(j+x<n&&k<n)
                        {
                            if(maps[j+x][k]=='@')
                            {
                                //fk=1;
                                x++;
                                chk[j+x][k]=1;
                            }
                            else if(maps[j+x][k]=='x')
                            {
                                x++;
                                chk[j+x][k]=1;
                            }
                            else
                            {
                                break;
                            }
                        }
                        while(j<n&&k+y<n){
                            if(maps[j][k+y]=='@')
                            {
                                //fk=1;
                                y++;
                                chk[j][k+y]=1;
                            }
                            if(maps[j][k+y]=='x')
                            {
                                y++;
                                chk[j][k+y]=1;
                            }
                            else
                            {
                                break;
                            }
                        }

                    }
                    if(maps[j][k]=='@')
                    {
                        fk=1;
                        printf("%d %d = %c\n",j,k,maps[j][k]);
                        cot++;
                        while(j+x<n&&k<n)
                        {
                            if(maps[j+x][k]=='@')
                            {
                                //fk=1;
                                x++;
                                chk[j+x][k]=1;
                            }
                            if(maps[j+x][k]=='x')
                            {
                                fk=0;
                                x++;
                                chk[j+x][k]=1;
                            }
                            else
                            {
                                break;
                            }
                        }
                        while(j<n&&k+y<n){
                            if(maps[j][k+y]=='@')
                            {
                                //fk=1;
                                y++;
                                chk[j][k+y]=1;
                            }
                            if(maps[j][k+y]=='x')
                            {
                                y++;
                                fk=0;
                                chk[j][k+y]=1;
                            }
                            else
                            {
                                break;
                            }
                        }
                        if(fk==1)cot--;
                    }
                }

                chk[j][k]=1;
            }
        }
        printf("Case %d: %d\n",i+1,cot);
    }
}
