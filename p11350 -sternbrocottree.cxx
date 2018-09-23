#include<bits/stdc++.h>
using namespace std;
char str[135];
int main()
{
    unsigned long long T,i,j,k,a1,a2,b1,b2,len,c1,c2;
    scanf("%llu",&T);
    while(T--)
    {
        scanf("%s",str);
        len=strlen(str);
        a1=0;a2=1;b1=1;b2=0;
        for(i=0;i<len;i++)
        {
            c1=a1+b1;c2=a2+b2;
            if(str[i]=='L')
            {
                b1=c1;b2=c2;
            }
            else
            {
                a1=c1;a2=c2;
            }
        }
        printf("%llu/%llu\n",a1+b1,a2+b2);

    }
}
