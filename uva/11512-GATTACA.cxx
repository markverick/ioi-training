#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
char s[2135];
int ranked[2135];
vector<char> v;
int rnk[500],same[2135],teema[2135];
int out[2135];
vector<pair<pair<int,int>,int> > p;
int main()
{
    freopen("out.txt","w",stdout);
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
        for(i=1;i<len;i++)
        {
            for(j=0;j<len;j++)
            {
                if(s[teema[i]+j]!=s[teema[i-1]+j])
                {
                    same[i]=j;
                    break;
                }
            }
        }
        int mc=0;
        for(i=1;i<len;i++)
        {
            mc=max(mc,same[i]);
        }
        int fu=0;
        for(i=1;i<len;i++)
        {
            if(same[i]>0&&same[i]==mc)
            {
                fu=1;
                for(j=teema[i];j<teema[i]+same[i];j++)
                    printf("%c",s[j]);
                for(j=i+1;j<=len;j++)
                {
                    if(j==len||same[i]!=same[j])
                    {
                        printf(" %d\n",j-i+1);
                        break;
                    }
                }
                break;
            }
        }
        if(fu==0)
            printf("No repetitions found!\n");
    }

}
