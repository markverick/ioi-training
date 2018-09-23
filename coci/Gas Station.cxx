#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<pair<int,int> > v;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int L,G,i,j,k,a,b,cot=0;
	while(scanf("%d %d",&L,&G)!=EOF)
    {
        if(L==0&&G==0)
            return 0;
        v.clear();cot=0;
        for(i=1;i<=G;i++)
        {
            scanf("%d %d",&a,&b);
            v.emplace_back(a+b,a-b);
        }
        sort(v.begin(),v.end());
        j=0;
        cot=1;
        for(i=1;i<v.size();i++)
        {
            while(v[j].X>v[i].Y)
            {
                j++;
            }
            cot++;
        }
        printf("! %d\n",G-cot);
    }
}
