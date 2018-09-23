#include<bits/stdc++.h>
using namespace std;
char s1[1200],s2[1200];
int jum[1200][1200];

int main()
{
    int l1,l2;
    scanf("%s %s",s1,s2);
    memset(jum,-1,sizeof jum);
    l1=strlen(s1);
    l2=strlen(s2);
    int i,j;
    int sum=0;
    int hi=0;
    j=0;
    int k=0;
    for(i=0;i<l1;i++)
    {
        for(j=0;j<l2;j++)
        {
            sum=0;
            if(s1[i]==s2[j])
            {
                for(k=0;true;k++)
                {
                    if(i+k<l1&&j+k<l2&&s1[i+k]==s2[j+k])
                    {
                        sum++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            hi=max(hi,sum);
        }

    }
    printf("%d\n",hi);
}

