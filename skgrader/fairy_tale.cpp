#include<bits/stdc++.h>

char str[30][100];
int n;
int len=0;
char n1[50][20];
char n2[50][20];
char n3[50][20];
//strcpy("twenty",n1[20]);
void print(int p3,int p2,int p1)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(str[i][0]!='$')
            printf("%s ",str[i]);
        else
        {
            if(p2!=1)
                printf("%s%s%s ",n3[p3],n2[p2],n1[p1]);
            else
                printf("%s%s ",n3[p3],n1[10+p1]);
        }

    }
}
int main()
{
    strcpy(n1[1],"one");
    strcpy(n1[2],"two");
    strcpy(n1[3],"three");
    strcpy(n1[4],"four");
    strcpy(n1[5],"five");
    strcpy(n1[6],"six");
    strcpy(n1[7],"seven");
    strcpy(n1[8],"eight");
    strcpy(n1[9],"nine");
    strcpy(n1[10],"ten");
    strcpy(n1[11],"eleven");
    strcpy(n1[12],"twelve");
    strcpy(n1[13],"thirteen");
    strcpy(n1[14],"fourteen");
    strcpy(n1[15],"fifteen");
    strcpy(n1[16],"sixteen");
    strcpy(n1[17],"seventeen");
    strcpy(n1[18],"eighteen");
    strcpy(n1[19],"nineteen");
    strcpy(n2[2],"twenty");
    strcpy(n2[3],"thirty");
    strcpy(n2[4],"forty");
    strcpy(n2[5],"fifty");
    strcpy(n2[6],"sixty");
    strcpy(n2[7],"seventy");
    strcpy(n2[8],"eighty");
    strcpy(n2[9],"ninety");
    strcpy(n3[1],"onehundred");
    strcpy(n3[2],"twohundred");
    strcpy(n3[3],"threehundred");
    strcpy(n3[4],"fourhundred");
    strcpy(n3[5],"fivehundred");
    strcpy(n3[6],"sixhundred");
    strcpy(n3[7],"sevenhundred");
    strcpy(n3[8],"eighthundred");
    strcpy(n3[9],"ninehundred");

    int i,j,k;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%s",str[i]);
        if(str[i][0]!='$')
            len+=strlen(str[i]);

    }
    //print(5,1,7);
    //system("pause");
    //30303030 30
    for(i=len+1;i<=len+30;i++)
    {
        if(i/100!=0)
        {
            if((i%100)/10!=1)
            {
                if(strlen(n3[i/100])+strlen(n2[(i%100)/10])+strlen(n1[i%10])==i-len)
                {
                    print(i/100,(i%100)/10,i%10);
                    break;
                }
            }
            else
            {
                if(strlen(n3[i/100])+strlen(n1[i%10+10])==i-len)
                {
                    print(i/100,(i%100)/10,i%10);
                    break;
                }
            }

        }
        else
        {
            if((i%100)/10!=0)
            {
                if((i%100)/10!=1)
                {
                    if(strlen(n2[(i%100)/10])+strlen(n1[i%10])==i-len)
                    {
                        print(0,(i%100)/10,i%10);
                        break;
                    }
                }
                else
                {
                    if(strlen(n1[i%10+10])==i-len)
                    {
                        print(0,(i%100)/10,i%10);
                        break;
                    }
                }

            }
            else
            {
                if(strlen(n1[i%10])==i-len)
                {
                    print(0,0,i%10);
                    break;
                }
            }
        }
    }
    //printf("%d\n",len);
}
