#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
set<pair<int,int> > st;
set<pair<int,int> > ::iterator it;
int p[1000135];
char ch[3];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,l,r,a,b;
	scanf("%d %d %d",&n,&l,&r);
	for(i=1;i<=n;i++)
    {
        st.insert(MP(-0,-i));
    }
	for(i=1;i<=l+r;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='L'||ch[0]=='C')
        {
            scanf("%d %d",&a,&b);
            it=st.find(MP(-p[b],-b));
            if(ch[0]=='L')
                p[b]++;
            else
                p[b]+=3;
            st.erase(it);
            st.insert(MP(-p[b],-b));
        }
        else if(ch[0]=='R')
        {
            printf("%d\n",-(*st.begin()).Y);
        }
        else
        {
            st.erase(st.begin());
        }
    }
}
