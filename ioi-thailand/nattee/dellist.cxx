#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int L[100135],R[100135],nxt[100135];
vector<int> in[100135],out[100135],v[100135];
map<int,int> mp;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,a,b,ch;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        L[i]=i;R[i]=i;
        nxt[i]=i;
        while(a--)
        {
            scanf("%d",&k);
            v[i].emplace_back(k);
        }
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&ch,&a,&b);
        if(ch==1)
        {
            in[L[a]].emplace_back(b);
            out[R[a]].emplace_back(b);
        }
        else
        {
            nxt[R[a]]=L[b];
            R[a]=R[b];
            L[b]=L[a];
        }
    }
    for(i=1;i<=n;i++)
    {
        if(L[i]!=i)continue;
        k=i;
        while(135)
        {
            for(j=0;j<in[k].size();j++)
                mp[in[k][j]]++;
            for(j=0;j<v[k].size();j++)
            {
                if(mp[v[k][j]]==0)
                    printf("%d\n",v[k][j]);
            }
            for(j=0;j<out[k].size();j++)
                mp[out[k][j]]--;
            if(nxt[k]==k)
                break;
            k=nxt[k];
        }
    }
}
