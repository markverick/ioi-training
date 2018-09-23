#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> a,b;
multiset<int> sa,sb;
multiset<int> ::iterator it;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&j);
        if(j>=0)
            a.emplace_back(j);
        else
            sb.insert(-j);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&j);
        if(j>=0)
            b.emplace_back(j);
        else
            sa.insert(-j);
    }
    int cot=0;
    for(i=0;i<a.size();i++)
    {
        it=sa.upper_bound(a[i]);
        if(it!=sa.end())
        {
            cot++;
            sa.erase(it);
        }
    }
    for(i=0;i<b.size();i++)
    {
        it=sb.upper_bound(b[i]);
        if(it!=sb.end())
        {
            cot++;
            sb.erase(it);
        }
    }
    printf("%d",cot);
}
