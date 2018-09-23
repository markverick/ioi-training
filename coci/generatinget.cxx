#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> v[50135];
int a[50135];
unordered_map<int,bool> hsh;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,fs=1,md,ls,mn,MI,mc=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        MI=max(MI,a[i]);
        k=a[i];
        while(k>0)
        {
//            printf("%d ",k);
            v[i].emplace_back(k);
            k/=2;
        }
        sort(v[i].begin(),v[i].end());
//        printf("\n");
    }
    int fu=0;
    mn=MI;ls=MI;
    while(fs<=ls)
    {
        md=(fs+ls)/2;
        hsh.clear();
        fu=0;

        for(i=1;i<=n;i++)
        {
            mc=0;
            for(j=0;j<v[i].size();j++)
            {
                if(v[i][j]>md)
                    continue;
                if(hsh[v[i][j]])continue;
                mc=v[i][j];
                break;
            }
            if(mc==0)
            {
                fu=1;
                break;
            }
            hsh[mc]=1;
        }
        if(fu==1)
        {
            fs=md+1;
        }
        else
        {
            mn=min(mn,md);
            ls=md-1;
        }
    }
    hsh.clear();
    fu=0;
    md=mn;
    vector<int> out;
    for(i=1;i<=n;i++)
    {
        mc=0;
        for(j=v[i].size()-1;j>=0;j--)
        {
            if(v[i][j]>md)
                break;
            if(hsh[v[i][j]])continue;
            mc=max(mc,v[i][j]);
        }
        out.emplace_back(mc);
        hsh[mc]=1;
    }
    for(i=0;i<out.size();i++)
        printf("%d ",out[i]);
}
