#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main()
{
    int i,j,k,T,len,fk=0;
    char tmp=0;
    string a,b;
    vector<char> v;
    scanf("%d",&T);
    while(T--)
    {
        v.clear();a.clear();b.clear();
        fk=0;
        scanf("%s",s+1);
        len=strlen(s+1);
        for(i=len/2;i>=1;i--)
        {
            a.push_back(s[i]);
            b.push_back(s[(len+1)/2+len/2-i+1]);
        }
        if(a>b)
        {
            for(i=1;i<=len/2;i++)
                printf("%c",s[i]);
            if(len%2==1)
                printf("%c",s[len/2+1]);
            for(i=len/2;i>=1;i--)
                printf("%c",s[i]);
        }
        else
        {
            v.clear();fk=0;
            tmp=0;
            if(len%2&&s[len/2+1]<'9')
            {
                tmp=s[len/2+1]+1;
                fk=1;
                for(i=1;i<=len/2;i++)
                    v.emplace_back(s[i]);
            }
            else for(i=len/2;i>=1;i--)
            {
                if(s[i]<'9')
                {
                    for(j=1;j<i;j++)
                    {
                        v.emplace_back(s[j]);
                    }
                    v.emplace_back(s[i]+1);
                    for(j=i+1;j<=len/2;j++)
                    {
                        v.emplace_back('0');
                    }
                    tmp='0';
                    fk=1;
                    break;
                }
            }
            if(fk==1)
            {
                for(i=0;i<v.size();i++)
                    printf("%c",v[i]);
                if(len%2)
                    printf("%c",tmp);
                for(i=v.size()-1;i>=0;i--)
                    printf("%c",v[i]);
            }
            else
            {
                printf("1");
                for(i=1;i<len;i++)
                    printf("0");
                printf("1");
            }
        }
        printf("\n");
    }
}
