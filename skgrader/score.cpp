#include<bits/stdc++.h>

char str[120];
int main()
{
    int t,T,i,j,k;
    scanf("%d",&T);
    int score=0;
    for(t=0;t<T;t++)
    {
        score=0;
        scanf("%s",str);
        int len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(str[i]=='O')
            {
                for(j=i;true;j++)
                {
                    if(str[j]=='O')
                    {
                        score+=j-i+1;
                    }
                    else
                        break;
                }
                i=j;
            }
        }
        printf("%d\n",score);
    }
}
