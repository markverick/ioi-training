#include<bits/stdc++.h>

int main()
{
    int n;
    int i,j,k,l;
    char meow[2000];
    char num[50];
    char word[4]={'m','e','o','w'};
    int chck=0;
    int len;
    int length=0;
    gets(num);
    n=atoi(num);
    int fack;
    for(i=0;i<n;i++)
    {
        chck=1;fack=1;
        k=0;
        gets(meow);
        len=strlen(meow);
        for(j=0;k<len&&meow[k]!=' ';j++) //words
        {
            chck=1;
            length=0;
            fack=0;
            if(meow[k]!=' '){
                for(l=0;meow[k]!=' '&&meow[k]!='\0';l++)
                {
                    length++;
                    //printf("NumWord[%d]%c-%c chck = %d\n",j,word[l%4],meow[k],chck);
                    if(meow[k]==word[l%4])
                    {
                    }
                    else
                    {
                        fack=1;
                    }
                    k++;
                }
                //printf("%d",length);
                if(length%4!=0)
                {
                    fack=1;
                }
                if(fack==0)
                {
                    chck=0;
                }

            }
            k++;
            //printf("%d\n",length);
            if(chck==0)break;
        }

        if(chck==1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
}
