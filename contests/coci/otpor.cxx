#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
double r[12];
//stack<pair<double,char> > st[50135];
pair<double,char> st[50135];
char s[100135];
double par(double x,double y)
{
    return 1/(1/x+1/y);
}
int main()
{
    int n,i,j,k,len,lv=0;
    scanf("%d",&n);
    for(i=0;i<=50000;i++)
    {
        st[i].Y='-';
    }
    for(i=1;i<=n;i++)
    {
        scanf("%lf",&r[i]);
    }
    scanf("%s",s+1);
    len=strlen(s+1);
    for(i=1;i<=len;i++)
    {
//        printf("s[%d] = %c LV = %d %f\n",i,s[i],lv,st[lv]);
//        system("pause");
        if(s[i]=='-')
        {
            st[lv].Y='-';
        }
        else if(s[i]=='|')
        {
            st[lv].Y='|';
        }
        if(s[i]=='(')
        {
            lv++;
        }
        else if(s[i]==')')
        {
            if(st[lv-1].Y=='-')
                st[lv-1].X+=st[lv].X;
            else
                st[lv-1].X=par(st[lv-1].X,st[lv].X);
            lv--;
        }
        else if(s[i]=='R')
        {
            i++;
            if(s[i-2]=='(')
            {
                st[lv]=MP(r[s[i]-'0'],s[i+1]);
            }
            else
            {
                if(st[lv].Y=='-')
                    st[lv].X+=r[s[i]-'0'];
                else
                    st[lv].X=par(r[s[i]-'0'],st[lv].X);
            }
        }
    }
    printf("%f",st[1].X);
}
