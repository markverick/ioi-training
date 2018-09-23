#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char str[135],s[1135][20];
int p[1135][20],len[1135],hsh[300],P[135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,T,n,l,I;
	gets(str);
	sscanf(str,"%d",&n);
	for(i=1;i<=n;i++)
    {
        gets(s[i]);
        len[i]=strlen(s[i]);
        for(j=0;j<len[i];j++)
            p[i][j]=j;
        memset(hsh,-1,sizeof hsh);
        for(j=0;j<len[i];j++)
        {
            if(hsh[s[i][j]]>=0)
                p[i][j]=hsh[s[i][j]];
            hsh[s[i][j]]=j;
        }
    }
    string ss;
    int fk=0,fu=0;
    while(gets(str))
    {
        l=strlen(str);
        str[l++]=' ';
        j=0;
        for(i=0;i<l;i++)
        {
            fu=0;
            if(str[i]==' ')
            {
                ss.clear();
                for(k=j;k<i;k++)
                    ss.push_back(str[k]);

                for(k=1;k<=n;k++)
                {
                    if(len[k]!=ss.size())continue;
//                    printf("!%d\n",k);
                    memset(hsh,-1,sizeof hsh);fk=0;
                    for(I=0;I<ss.size();I++)
                    {
                        if(hsh[ss[I]]>=0)
                            P[I]=hsh[ss[I]];
                        else
                            P[I]=I;
                        hsh[ss[i]]=I;
                        if(P[I]!=p[k][I])
                        {
                            fk=1;
                            break;
                        }
                    }
                    if(fk==0)
                    {
                        fu=1;
                        printf("%s ",s[k]);
                        break;
                    }
                }
                j=i+1;
                if(fu==0)
                {
                    for(k=0;k<ss.size();k++)
                        printf("*");
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}
