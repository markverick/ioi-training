#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > maps;
vector<vector<int> > blank;
char in[3];
int len;
vector<vector<int> > matPow(long long a,long long b)
{
    if(b==0)
    {
        return blank;
    }
    vector<vector<int> > tmp=matPow(a,b/2);
    tmp*=tmp;
    tmp%=1000000007;
    if(b%2==1)
        tmp*=a;
    return tmp%=1000000007;
}
int main()
{
    int i,j,k;
    maps.resize(26);
    blank.resize(26);
    for(i=0;i<26;i++)
    {
        maps[i].resize(26);
        blank[i].resize(26);
        for(j=0;j<26;j++)
        {
            scanf("%d",&maps[i][j]);
        }
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s %d",in,&len);

    }
}
