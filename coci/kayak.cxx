#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int pos[11],out[11];
char s[55][55];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,r,c;
	scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
    {
        scanf("%s",s[i]+1);
    }
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(s[i][j]>='1'&&s[i][j]<='9')
                pos[s[i][j]-'0']=j;
        }
    }
    vector<pair<int,int> > v;
    for(i=1;i<=9;i++)
        v.emplace_back(pos[i],i);
    sort(v.begin(),v.end());
    j=1;
    out[v[v.size()-1].Y]=j;
    for(i=v.size()-2;i>=0;i--)
    {
        if(v[i].X!=v[i+1].X)
            j++;
        out[v[i].Y]=j;
    }
    for(i=1;i<=9;i++)
    {
        printf("%d\n",out[i]);
    }
}
