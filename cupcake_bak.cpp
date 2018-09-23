#include<bits/stdc++.h>
int aS,bS,cS;
char str[80];
int len;
char init;
int dp(int idx,char ch,int a,int b,int c)
{
    int i,j,k;
    char t;
    if(a>aS||b>bS||c>cS)
            return 0;
    if(idx==len)
    {

        if(ch!=init)
            return 1;
        else
            return 0;
    }
    int sum=0;
    switch (ch)
    {
    case 'a':
        if(b<bS)
            sum+=dp(idx+1,'b',a,b+1,c);
        if(c<cS)
            sum+=dp(idx+1,'c',a,b,c+1);
    case 'b':
        if(a<aS)
            sum+=dp(idx+1,'a',a+1,b,c);
        if(c<cS)
            sum+=dp(idx+1,'c',a,b,c+1);
    case 'c':
        if(a<aS)
            sum+=dp(idx+1,'a',a+1,b,c);
        if(b<bS)
            sum+=dp(idx+1,'b',a,b+1,c);
    }
    return sum;
}
int main()
{
    int i,j,k;
    while(scanf("%s",str)!=EOF)
    {
        aS=0;bS=0;cS=0;
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            switch (str[i])
            {
                case 'A': aS++;break;
                case 'B': bS++;break;
                case 'C': cS++;break;
            }
        }
        init='a';
        printf("%d\n",dp(1,'a',1,0,0));
        init='b';
        printf("%d\n",dp(1,'b',0,1,0));
        init='c';
        printf("%d\n",dp(1,'c',0,0,1));
        //printf("%d %d %d\n",a,b,c);
        memset(str,0,sizeof str);
    }
}
