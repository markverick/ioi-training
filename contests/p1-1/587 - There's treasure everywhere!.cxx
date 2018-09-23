#include<bits/stdc++.h>
using namespace std;
char s[222];
int main()
{
    int sum=0,i,j,k,T=0,len;
    double x,y;
    while(scanf("%s",s+1)!=EOF)
    {
        x=0;y=0;
        T++;
        if(s[1]=='E')
            return 0;
        len=strlen(s+1);
        sum=0;
        for(i=1;i<=len;i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                sum*=10;
                sum+=s[i]-'0';
            }
            if(s[i]=='N'||s[i]=='S'||s[i]=='E'||s[i]=='W')
            {
                if(s[i+1]=='.'||s[i+1]==',')
                {
                    if(s[i]=='N')
                        y+=sum;
                    else if(s[i]=='S')
                        y-=sum;
                    else if(s[i]=='E')
                        x+=sum;
                    else if(s[i]=='W')
                        x-=sum;
                }
                else
                {
                    if(s[i]=='N')
                        y+=sum/sqrt(2);
                    else if(s[i]=='S')
                        y-=sum/sqrt(2);
                    else if(s[i]=='E')
                        x+=sum/sqrt(2);
                    else if(s[i]=='W')
                        x-=sum/sqrt(2);
                    if(s[i+1]=='N')
                        y+=sum/sqrt(2);
                    else if(s[i+1]=='S')
                        y-=sum/sqrt(2);
                    else if(s[i+1]=='E')
                        x+=sum/sqrt(2);
                    else if(s[i+1]=='W')
                        x-=sum/sqrt(2);
                    i++;
                }
                sum=0;
            }
        }
        printf("Map #%d\n",T);
        printf("The treasure is located at (%.3lf,%.3lf).\n",x,y);
        printf("The distance to the treasure is %.3lf.\n\n",sqrt(x*x+y*y));
    }
}
