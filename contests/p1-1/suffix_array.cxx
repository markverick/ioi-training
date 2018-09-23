#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
char s[100135];
int ranked[100135];
vector<char> v;
int rnk[500];
int out[100135];
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
        ranked[i]=s[i];
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
        out[ranked[i]]=i;
//        for(j=ranked[i];j<len;j++)
//            printf("%c",s[j]);
//        printf("\n")
    }
    for(i=0;i<len;i++)
    {
        for(j=out[i];j<len;j++)
            printf("%c",s[j]);
        printf("\n");
//        printf("%d\n",ranked[i]);
//        for(int j=p[i].Y;j<len;j++)
//            printf("%c",s[j]);
//        printf("\n");
    }
}
