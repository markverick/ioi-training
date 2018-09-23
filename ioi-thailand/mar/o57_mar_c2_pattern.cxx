#include<bits/stdc++.h>
using namespace std;
char s[100135],t[100135];
int pi[100135];
int hsh[500];
int main()
{
    int n,q,i,j,k,len,cot=0;
    scanf("%d %d",&n,&q);
    scanf("%s",t);
    while(q--)
    {
        scanf("%d %s",&len,s);
        for(i='a';i<='z';i++)
            hsh[i]=-1;
        for(i=0;i<len-1;i++)
        {
            if(s[i]=='?')
            {
                for(j='a';j<='z';j++)
                    hsh[j]=i;
            }
            else
                hsh[s[i]]=i;
        }
        i=0;
        cot=0;
        while(i<=n-len)
        {
            j=len-1;
            while(j>=0&&(t[i+j]==s[j]||s[j]=='?')) j--;
            if(j<0)
            {
                cot++;
            }
            i+=len-1;
            i-=hsh[t[i]];
        }
        printf("%d\n",cot);
    }
}
