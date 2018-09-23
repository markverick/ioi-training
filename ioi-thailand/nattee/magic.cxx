#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int ch;
vector<pair<int,int> > v[200135];
set<pair<int,int> > st;
set<pair<int,int> > ::iterator it;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,a,b,c,d,t,T,ty;
	scanf("%d %d",&n,&m);
	T=n+m;
	for(t=1;t<=T;t++)
    {
        scanf("%d",&ch);
        if(ch==1)
        {
            scanf("%d",&ty);
            if(ty==1)
            {
                scanf("%d %d",&a,&b);
                st.insert(MP(a,b));
            }
            else if(ty==2)
            {
                scanf("%d %d %d",&a,&b,&c);
                st.insert(MP(a,b));
                v[c].emplace_back(a,0);
            }
            else if(ty==3)
            {
                scanf("%d %d %d %d",&a,&b,&c,&d);
                st.insert(MP(a,b));
                v[c].emplace_back(a,d);
            }
        }
        else
        {
            if(st.empty())
                printf("0\n");
            else
            {
                printf("%d\n",(*st.begin()).Y);
                st.erase(st.begin());
            }
        }
        for(i=0;i<v[t].size();i++)
        {
            it=st.lower_bound(MP(v[t][i].X,0));
            if(it==st.end())continue;
            if((*it).X==v[t][i].X)
            {
                if(v[t][i].Y)
                    st.insert(MP(v[t][i].Y,(*it).Y));
                st.erase(it);
            }
        }
    }
}
