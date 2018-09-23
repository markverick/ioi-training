#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
int n;
vector<int> pi;
string s[20005];
int hsh[20005];
tuple<int,string,int> p[20135];
int main()
{
//    freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,Q;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> s[i];
        p[i]=make_tuple(s[i].size(),s[i],i);
    }
    sort(&p[1],&p[n+1]);
    cin >> Q;
    string pat;
    int fu=0;
    while(Q--)
    {
        pi.clear();
        cin >> pat;
        j=0;
        pi.emplace_back(j);
        for(i=1;i<pat.size();i++)
        {
            while(j>0&&pat[j]!=pat[i])
                j=pi[j-1];
            if(pat[i]==pat[j])
                j++;
            pi.emplace_back(j);
        }
        memset(hsh,0,sizeof hsh);
        for(k=1;k<=n;k++)
        {
            j=0;
            for(i=0;i<(get<1>(p[k])).size();i++)
            {
                while(j>0&&(get<1>(p[k]))[i]!=pat[j])
                    j=pi[j-1];
                if((get<1>(p[k]))[i]==pat[j])
                {
                    j++;
                }
                if(j==pat.size())
                {
                    hsh[k]=1;
                    j=pi[j-1];
                }
            }
        }
        fu=0;
        for(i=1;i<=n&&fu<10;i++)
        {
            if(hsh[i]==1)
            {
                if(fu==0)
                    cout << get<2>(p[i]);
                else
                    cout << " "<< get<2>(p[i]);
                fu++;
            }
        }
        if(fu==0)
            cout << "-1";
        cout << "\n";
    }
}
