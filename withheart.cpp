#include<bits/stdc++.h>
using namespace std;
char str[1300];
char stk[1300];
int main()
{
    int t,T,idx=0;
    scanf("%d",&T);
    int i,j,k;
    int sum=0;
    for(t=0;t<T;t++)
    {
        memset(stk,0,sizeof stk);
        memset(str,0,sizeof str);
        int chck=0;
        int x=0;
        int y=0;
        idx=0;
        scanf("%s",str);
        int len=strlen(str);
        for(j=0;j<len;j++)
        {

            if(str[j]=='[')
            {
                x+=1;y=max(y,x);
                stk[idx++]='[';
            }
            else if(str[j]=='6')
            {
                x+=2;y=max(y,x);
                stk[idx++]='6';
            }
            else if(str[j]=='q')
            {
                x+=3;y=max(y,x);
                stk[idx++]='q';
            }
            else if(str[j]=='d')
            {
                x+=4;y=max(y,x);
                stk[idx++]='d';
            }
            else if(str[j]=='*')
            {
                x+=5;y=max(y,x);
                //y=max(y,x+5); //*[*[**]**]
            }
            else if(str[j]==']')
            {
                if(idx<1)
                {
                    chck=1;
                    break;
                }

                if(stk[idx-1]=='[')
                    idx--;
                else
                    chck=1;
                x-=1;
            }
            else if(str[j]=='9')
            {
                if(idx<1)
                {
                    chck=1;
                    break;
                }

                if(stk[idx-1]=='6')
                    idx--;
                else
                    chck=1;
                x-=2;
            }
            else if(str[j]=='p')
            {
                if(idx<1)
                {
                    chck=1;
                    break;
                }

                if(stk[idx-1]=='q')
                    idx--;
                else
                    chck=1;
                x-=3;
            }
            else if(str[j]=='b')
            {
                if(idx<1)
                {
                    chck=1;
                }
                if(stk[idx-1]=='d')
                    idx--;
                else
                    chck=1;
                x-=4;
            }
            if(chck==1)
                break;
        }

        if(chck==0)
        {
            //printf("%d\n",y);
            sum=max(sum,y);
        }
    }
    printf("%d",sum);
}
