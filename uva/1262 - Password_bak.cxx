#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
char s[1000135];
int ranked[1000135];
vector<char> v;
int rnk[500];
int out[1000135],teema[1000135];
vector<pair<pair<int,int>,int> > p;
int main()
{
    scanf("%s",s);
    int len=strlen(s),i,j,c;
    for(i=0;i<len;i++)
    {
        v.emplace_back(s[i]);
        p.emplace_back(make_pair(-1,-1),-1);
    }
    sort(v.begin(),v.end());
    auto it135=unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it135));
    for(i=0;i<v.size();i++)
    {
        rnk[v[i]]=i;
    }
    for(i=0;i<len;i++)
    {
        ranked[i]=rnk[s[i]];
    }
    for(i=1;i<=len;i*=2)
    {
        for(j=0;j<len;j++)
        {
            p[j].X.X=ranked[j];
            p[j].Y=j;
        }
        for(j=0;j<len-i;j++)
        {
            p[j].X.Y=ranked[j+i];
        }
        for(j=len-i;j<len;j++)
            p[j].X.Y=-1;
        sort(p.begin(),p.end());
        c=0;
        ranked[p[0].Y]=0;
        for(j=1;j<p.size();j++)
        {
            if(p[j].X.X==p[j-1].X.X&&p[j].X.Y==p[j-1].X.Y)
                ranked[p[j].Y]=c;
            else
            {
                c++;
                ranked[p[j].Y]=c;
            }
        }
    }
    for(i=0;i<len;i++)
    {
        teema[ranked[i]]=i;
    }
    int k=ranked[0];
    j=len-1;
    if(j<0)
    {
        printf("Just a legend yo\n");
//        continue;
        return 0;
    }
    int fu=0,yeah=len;
    for(i=k-1;i>=0;i--)
    {
        while(s[j]!=s[teema[i]+j])
        {
            j--;
        }
        if(j+1==len-teema[i])
        {
            yeah=teema[i];
            break;
        }
        fu++;
    }
    if(fu==0)
    {
        for(i=0;i<len;i++)
        {
            if(s[i]!=s[teema[k+1]+i])
            {
                if(i==len-yeah)
                {
                    for(j=0;j<i;j++)
                    {
                        printf("%c",s[j]);
                    }
                    printf("\n");
                }
                else
                {
                    printf("Just a legend\n");
                }
                break;
            }
        }
    }
    else
    {
        for(i=yeah;i<len;i++)
        {
            printf("%c",s[i]);
        }
        printf("\n");
    }
}

