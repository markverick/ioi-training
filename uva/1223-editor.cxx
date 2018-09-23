#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
char s[5005];
int ranked[5005];
vector<char> v;
int rnk[500],same[5005],teema[5005];
int out[5005];
vector<pair<pair<int,int>,int> > p;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(ranked,0,sizeof ranked);
        memset(s,0,sizeof s);
        v.clear();p.clear();
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
        int mc=0;
        for(i=1;i<len;i++)
        {
            for(j=0;j<len;j++)
            {
                if(s[teema[i]+j]!=s[teema[i-1]+j])
                {
                    mc=max(mc,j);
                    break;
                }
            }
        }
        printf("%d\n",mc);
    }

}

