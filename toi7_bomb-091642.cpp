#include<bits/stdc++.h>
#define MP make_pair
#define MT(x,y,z) make_pair(make_pair(x,y),z)
#define PB push_back
#define X first
#define Y second
using namespace std;
int n;
pair<int,int> a[1000005];
pair<int,int> b[1000005];
vector<pair<int,int> > c;
multiset<pair<int,int> >st;
multiset<pair<int,int> >::iterator it;
map<pair<int,int>,char > hsh;
int main()
{
    scanf("%d",&n);
    int i,j,k;
    for(i=0;i<n;i++)
    {
        int aa,bb;
        scanf("%d %d",&aa,&bb);
        a[i]=MP(aa,bb);
        b[i]=MP(bb,aa);
        st.insert(MP(aa,bb));
        st.insert(MP(aa,bb));
    }
    sort(&a[0],&a[n]);
    sort(&b[0],&b[n]);
    for(i=1;i<n;i++)
    {
        if(a[i].X>a[i-1].X&&a[i].Y>a[i-1].Y)
            st.erase(MP(a[i-1].X,a[i-1].Y));
        if(b[i].X>b[i-1].X&&b[i].Y>b[i-1].Y)
            st.erase(MP(b[i-1].Y,b[i-1].X));
    }
    /*for(i=0;i<n;i++)
    {
        if(hsh[i]==0)
        {
            c.push_back(d[i]);
        }
    }*/
    sort(c.begin(),c.end());
    pair<int,int> out;
    for(it=st.begin();it!=st.end();it++)
    {
        if(out==*it)
            continue;
        out=*it;
        printf("%d %d\n",out.X,out.Y);
    }
}
