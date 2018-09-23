#include<bits/stdc++.h>
char str[100];
int main()
{
    int chck=0;
    int n;
    int i,j,k;
    int len;
    int progress=0; // 0 is start without words // 1 is "da" // 2 is "daa..."
    // 3 is "daa..aad" // 4 is "daa..aad(d) // 5 is "daa..aad(d)(i|y) //YEAH o m e l e t
    while(scanf("%s",str)!=EOF)
    {
        progress=0;
        chck=0;
        len=strlen(str);
        if(str[0]!='d'||str[1]!='a')chck=1;
        progress=1; //daaddy
        for(i=2;i<len;i++)
        {
            if(chck==1)break;
            switch(progress)
            {
            case 1:
                if(str[i]=='d')
                {
                    progress=3;
                }
                else if(str[i]!='a')
                {
                    chck=1;
                }
                break;
            case 3:
                if(str[i]=='d')
                {
                    progress=4;
                }
                else if(str[i]=='i'||str[i]=='y')
                {
                    progress=5;
                }
                else
                {
                    chck=1;
                }
                break;
            case 4:
                if(str[i]=='i'||str[i]=='y')
                {
                    progress=5;
                }
                else
                {
                    //printf("[%d]=%c\n",i,str[i]); //NOOO OMELET FLAGGOT ONLY 1 BREAK;!
                    chck=1;
                }
                break;
            case 5:
                if(i!=n-1)
                {
                    chck=1;
                }
                break;
            }
        }
        //printf("\t\t%d %d\n",progress,chck);
        if(chck==0&&progress==5)
            {
                printf("She called me!!!\n");
            }
            else
            {
                printf("Cooing\n");
            }
        memset(str,0,100);
        str[0]='\0';
    }
}
