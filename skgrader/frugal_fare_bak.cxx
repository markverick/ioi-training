#include<bits/stdc++.h>
using namespace std;
tuple<int,int,int> x[1135];
stack<tuple<int,int,int> > st;
//start end ppl
int main()
{
    int n,m,i,j,k,T,a,b,c,ai,bi,ci;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            x[i]=make_tuple(a,b,c);
        }
        sort(&x[1],&x[m+1]);
        for(i=1;i<=m;i++)
        {
            if(st.empty())
            {
                st.emplace_back(x[i]);
                continue;
            }
            tie(ai,bi,ci)=x[i].top();
            while(ci>0)
            {
                tie(a,b,c)=st.top();
                if(ci-c>=0)
                {
                    ci--;
                    st.pop();
                }
                else
                    break;
            }
            tie(a,b,c)=st.top();
            (a,b,c)
        }
    }
}
