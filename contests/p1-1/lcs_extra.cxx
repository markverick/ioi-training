#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
string s,a[10];
int ranked[10135];
vector<char> v;
int rnk[500];
int out[10135];
int group[10135];
int hsh[10],Hi[10];
vector<pair<pair<int,int>,int> > p;
int main()
{
    int n,i,j,c;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        s+=a[i];s+='$';
    }
    int len=s.size();
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
        out[ranked[i]]=i;
    }
    int b=0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<a[i].size();j++)
        {
            group[b++]=i;
        }
        group[b++]=0;
    }
    int x,y,fst=0,lst=0,mc=0,cot=0,co=0,pos,anchor,al,mn;
    while(fst<=len&&lst<=len)
    {
        cot=0;
        for(i=1;i<=n;i++)
        {
            if(hsh[i]>0)
                cot++;
        }
        if(cot==n)
        {
            memset(Hi,0,sizeof Hi);
            for(i=fst;i<lst;i++)
            {
                if(hsh[group[out[i]]]==1)
                {
                    anchor=i;
                    for(j=0;j<len;j++)
                    {
                        if(s[out[anchor]+j]=='$')
                            break;
                    }
                    al=j;
                    break;
                }
            }
            for(i=fst;i<lst;i++)
            {
                if(group[out[i]]==0||group[out[i]]==group[out[anchor]])
                    continue;
                for(pos=0;pos<al;pos++)
                {
                    if(s[out[i]+pos]=='$')
                        break;
                    if(s[out[anchor]+pos]!=s[out[i]+pos])
                        break;
                }
                Hi[group[out[i]]]=max(Hi[group[out[i]]],pos);
            }
            mn=1000000000;
            for(i=1;i<=n;i++)
            {
                if(i==group[out[anchor]])
                    continue;
                mn=min(mn,Hi[i]);
            }
            mc=max(mc,mn);
            hsh[group[out[fst++]]]--;
        }
        else
        {
            hsh[group[out[lst++]]]++;
        }
    }
    printf("%d",mc);
}
