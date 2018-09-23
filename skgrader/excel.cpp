#include<bits/stdc++.h>
using namespace std;
char str[12000000];
stack<char> st;
stack<int> si;
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        int len=strlen(str);
        int fu=0;
        for(i=0;i<len;i++)
        {
            if(i==0&&fu==0&&str[i]=='R')
                fu=1;
            else if(fu==1&&str[i]>='0'&&str[i]<='9')
                fu=2;
            else if(fu==2&&str[i]=='C')
                fu=3;
        }
        //printf("%d\n",fu);
        if(fu==3)
        {
            int a,b;
            sscanf(str,"R%dC%d",&b,&a);
            while(a>0)
            {
                int b=(a)%26+'A'-1;
                if(b<'A')
                {
                    b='Z';
                    a--;
                }
                st.push(b);
                a/=26;
            }
            while(!st.empty())
            {
                printf("%c",st.top());
                st.pop();
            }
            printf("%d\n",b);
        }
        else
        {
            fu=0;
            for(i=0;i<len;i++)
            {
                if(fu==0&&str[i]>='A'&&str[i]<='Z')
                    st.push(str[i]);
                else if(fu==1)
                {
                    printf("%c",str[i]);
                }
                else
                {
                    printf("R%c",str[i]);
                    fu=1;
                }
            }
            int b=1;
            int sum=0;
            while(!st.empty())
            {
                int a=st.top()-'A'+1;
                sum+=b*a;
                b*=26;
                st.pop();
            }
            printf("C%d\n",sum);

        }
    }
}
