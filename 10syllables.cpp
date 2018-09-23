#include<bits/stdc++.h>
using namespace std;
char str[135];
int main()
{
    int n,i,j,k,len;
    scanf("%d",&n);
    for(j=1;j<=n;j++)
    {
        int cot=0;
        memset(str,0,sizeof str);
        scanf("%s",str+1);
        len=strlen(str+1);
        for(i=1;i<=len;i++)
        {
            switch(str[i])
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                str[i]=1;
            if(str[i]!=str[i-1])
                cot++;break;
            }

        }
        printf("%d\n",cot);

    }
}
