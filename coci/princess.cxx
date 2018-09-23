#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[100135],b[100135],c[100135],d[100135];
vector<pair<int,int> > P,N;
set<pair<int,int> > sp[100135],sn[100135];
set<pair<int,int> > ::iterator ip,in;
char s[100315];
int main()
{
	//freopen("out.txt","w",stdout);
//	freopen("in.txt","r",stdin);
	int i,j,k,n,m,id=1;
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        c[i]=a[i]+b[i];
        d[i]=a[i]-b[i];
        P.emplace_back(c[i],i);
        N.emplace_back(d[i],i);
    }
    sort(P.begin(),P.end());
    j=1;
    c[P[0].Y]=j;
    for(i=1;i<P.size();i++)
    {
        if(P[i].X==P[i-1].X)
            c[P[i].Y]=j;
        else
            c[P[i].Y]=++j;
    }
    sort(N.begin(),N.end());
    j=1;
    d[N[0].Y]=j;
    for(i=1;i<N.size();i++)
    {
        if(N[i].X==N[i-1].X)
            d[N[i].Y]=j;
        else
            d[N[i].Y]=++j;
    }
    for(i=1;i<=n;i++)
    {
        sp[c[i]].insert(MP(d[i],i));
        sn[d[i]].insert(MP(c[i],i));
    }
    id=1;
    for(i=1;i<=m;i++)
    {
        ip=sp[c[id]].lower_bound(MP(d[id],0));
        in=sn[d[id]].lower_bound(MP(c[id],0));
        switch(s[i])
        {
        case 'A':
            in++;
            if(in!=sn[d[id]].end())
            {
                in--;
                in=sn[d[id]].erase(in);
                sp[c[id]].erase(ip);
                id=(*in).Y;
            }
            break;
        case 'B':
            ip++;
            if(ip!=sp[c[id]].end())
            {
                ip--;
                ip=sp[c[id]].erase(ip);
                sn[d[id]].erase(in);
                id=(*ip).Y;
            }
            break;
        case 'C':
            if(ip!=sp[c[id]].begin())
            {
                ip=sp[c[id]].erase(ip);
                sn[d[id]].erase(in);
                ip--;
                id=(*ip).Y;
            }
            break;
        case 'D':
            if(in!=sn[d[id]].begin())
            {
                in=sn[d[id]].erase(in);
                sp[c[id]].erase(ip);
                in--;
                id=(*in).Y;
            }
            break;
        }
    }
    printf("%d %d",a[id],b[id]);
}
