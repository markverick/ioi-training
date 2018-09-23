#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[100135][13];
int mat[30][30];
vector<pair<int,int> > v;
map<pair<int,int>,int> mp;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,l,m,x,len;
	long long sum=0,prod;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%s",s[i]);
        len=strlen(s[i]);
        mat[s[i][0]-'A'][s[i][len-1]-'A']++;
    }
    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
        {
            for(k=0;k<26;k++)
            {
                for(l=0;l<26;l++)
                {
                    v.clear();prod=1;mp.clear();
                    v.emplace_back(i,j);
                    v.emplace_back(i,k);
                    v.emplace_back(j,l);
                    v.emplace_back(k,l);
                    for(m=0;m<v.size();m++)
                    {
                        mp[v[m]]++;
                    }
                    sort(v.begin(),v.end());
                    auto it=unique(v.begin(),v.end());
                    v.resize(it-v.begin());
                    for(m=0;m<v.size();m++)
                    {
                        x=mat[v[m].X][v[m].Y];
                        if(mp[v[m]]==1)
                            prod*=x;
                        else if(mp[v[m]]==2)
                            prod*=x*(x-1);
                        else if(mp[v[m]]==3)
                            prod*=x*(x-1)*(x-2);
                        else if(mp[v[m]]==4)
                            prod*=x*(x-1)*(x-2)*(x-3);
                    }
                    sum+=prod;
                }
            }
        }
    }
    printf("%lld",sum);
}
