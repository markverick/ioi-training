#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> hsh;
int a[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,x,mc=0;
	stack<pair<int,int> > st;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
    {
        while(!st.empty()&&st.top().X>=a[i])
        {
            st.pop();
        }
        if(st.empty())
            st.emplace(a[i],0);
        else
            st.emplace(a[i],max(st.top().Y,a[i]-st.top().X));
        if(!st.empty())
        {
//            printf("%d %d\n",i,st.top().Y);
            hsh.emplace_back(st.top().Y);
        }
    }
    sort(hsh.begin(),hsh.end());
//    for(i=0;i<hsh.size();i++)
//        printf("%d ",hsh[i]);
//    printf("\n");
    for(i=1;i<=m;i++)
    {
        scanf("%d",&x);
        printf("%d\n",hsh.size()-(upper_bound(hsh.begin(),hsh.end(),x)-hsh.begin()));
    }
}
