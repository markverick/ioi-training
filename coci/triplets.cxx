#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char maps[111][111];
vector<pair<int,int> > v;
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",maps[i]+1);
        for(j=1;j<=n;j++)
        {
            if(maps[i][j]!='.')
                v.emplace_back(i,j);
        }
    }
    sort(v.begin(),v.end());
    int cot=0;
    for(i=0;i<v.size();i++)
    {
        for(j=i+1;j<v.size();j++)
        {
            for(k=j+1;k<v.size();k++)
            {
                if((v[j].X-v[i].X)*(v[k].Y-v[i].Y)==(v[j].Y-v[i].Y)*(v[k].X-v[i].X))
                    cot++;
            }
        }
    }
    printf("%d",cot);
}
