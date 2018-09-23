#include<bits/stdc++.h>
#define Mod 1000003
using namespace std;
char s[100135][32],t[1000005];
int go[100135];
vector<int> hsh[1000005];
int dak[100135];
unordered_map<int,int> ha;
///prime = 1000003;
int main()
{
    int n,i,j,k,kn,ln,m,lm,sum=0,base=0,sm=0;
    scanf("%d %d",&n,&ln);
    for(i=1;i<=n;i++)
    {
        sum=0;sm=0;
        scanf("%s",s[i]);
        for(j=0;j<ln;j++)
        {
            sm*=2+s[i][j]-'0';
            sum*=2;
            sum+=s[i][j]-'0';
            sum%=Mod;
        }
        printf("%d\n",sum);
        if(ha.find(sm)==ha.end()) //new one
        {
            hsh[sum].emplace_back(i);
        }
        else
        {
            go[ha[sm]]=i;
        }
        ha[sm]=i;
    }
    while(m--)
    {
        scanf("%d %s",lm,t);
        sum=0;base=(1<<ln);base%=Mod;
        for(i=0;i<ln;i++)
        {
            sum*=2;
            sum+=t[i]-'0';
            sum%=Mod;
        }
        if(!hsh[sum].empty())
        {
            for(i=0;i<hsh[sum].size();i++)
            {
                if(dak[hsh[sum][i]]==0)
                {
                    for(j=0;j<ln)
                        dak[hsh[sum[i]]]
                }
            }
        }
        for(i=ln;i<lm;i++)
        {

        }
    }
}
