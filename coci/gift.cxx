#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
pair<int,int> p[100135];
int tema[100135];
vector<pair<int,int> > v;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d %d",&p[i].Y,&p[i].X);
        p[i].Y=-p[i].Y;
    }
    sort(&p[1],&p[n+1]);
//    for(i=n;i>=1;i--)
//    {
//        printf("%d ",-p[i].Y);
//    }
//    printf("\n");
    for(i=n;i>=1;i--)
    {
        j=upper_bound(v.begin(),v.end(),MP(-p[i].Y,100000000))-v.begin();
        if(j<v.size())
        {
            if(j==0)
                tema[i]=-1;
            else
                tema[i]=v[j-1].Y;
            v[j]=MP(-p[i].Y,i);
        }
        else
        {
            if(v.empty())
                tema[i]=-1;
            else
                tema[i]=v[v.size()-1].Y;
            v.emplace_back(-p[i].Y,i);
        }
//        for(j=0;j<v.size();j++)
//            printf("%d ",v[j].X);
//        system("pause");
    }
    printf("%d\n",v.size());
    stack<int> st;
    j=v[v.size()-1].Y;
    while(j>=0)
    {
        st.emplace(j);
        j=tema[j];
    }
    while(!st.empty())
    {
        x=st.top();
        st.pop();
        printf("%d %d\n",-p[x].Y,p[x].X);
    }
}
