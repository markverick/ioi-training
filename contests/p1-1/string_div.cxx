#include<bits/stdc++.h>
using namespace std;
char s[1135];
int hsh[500];
string a,b,c,d;
int main()
{
    int T,i,j,k,l,len,cot,fu=0;
    scanf("%d",&T);
    while(T--)
    {
//        printf("\n\n");
        cot=0;fu=0;
        memset(hsh,0,sizeof hsh);
        scanf("%s",s+1);
        len=strlen(s+1);
//        for(i=1;i<=len;i++)
//        {
//            if(hsh[s[i]]==0)
//            {
//                hsh[s[i]]=1;
//                cot++;
//            }
//        }
        if(len>=10)
        {
            printf("YES\n");
        }
        else
        {
            fu=0;
            for(i=1;i<len;i++)
            {
                for(j=i+1;j<len;j++)
                {
                    for(k=j+1;k<len;k++)
                    {
                        a.clear();b.clear();c.clear();d.clear();
                        for(l=1;l<=i;l++)
                        {
                            a+=s[l];
                        }
                        for(l=i+1;l<=j;l++)
                        {
                            b+=s[l];
                        }
                        for(l=j+1;l<=k;l++)
                        {
                            c+=s[l];
                        }
                        for(l=k+1;l<=len;l++)
                        {
                            d+=s[l];
                        }
                        if(a!=b&&b!=c&&c!=d&&a!=c&&a!=d&&b!=d)
                        {
//                            cout <<a<<"\n"<<b<<"\n"<<c<<"\n"<<d<<"\n";
                            fu=1;
                        }
                    }
                }
            }
            if(fu==1)
            {
                printf("YES\n");
            }
            else
                printf("NO\n");
        }
    }
}
