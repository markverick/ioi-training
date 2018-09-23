#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
char s[100135];
int ranked[100135];
vector<char> v;
int rnk[500];
int out[100135];
char b[100135][33];
int a[100135];
vector<pair<pair<int,int>,int> > p;
int main()
{
    int i,j,c,n,m,sum=0,q;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%s",b[i]);
        sum=0;
        for(i=0;i<m;i++)
        {
            sum+=b[i]-'0';
            sum*=2;
        }
        a[i]=sum;
    }
    scanf("%d",&q);
    while(q--)
    {
        v.clear();
        p.clear();
        scanf("%d %s",lens,ss);
        int lens=strlen(ss);
        for(i=0;i<lens/30;i++)
        {
            sum=0;
            for(j=0;j<30;j++)
            {
                sum+=ss[i*30+j]-'0';
                sum*=2;
            }
        }
        for(i=30*(lens/30);i<lens;i++)
        {
            s
        }
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
            printf("%d\n",ranked[i]+1);
        }
    }
}

