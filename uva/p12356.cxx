#include<bits/stdc++.h>
using namespace std;

set<int> st;
set<int> ::iterator it;
int main()
{
    //freopen("out.txt","w",stdout);
    int n,m,i,j,k,L,R;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            return 0;
        st.clear();
        for(i=1;i<=n;i++)
            st.insert(i);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&L,&R);
            it=st.lower_bound(L);
            if(it==st.begin())
                printf("* ");
            else
            {
                it--;
                printf("%d ",*it);
                it++;
            }
            //printf("%d\n",*it);
            while(it!=st.end()&&*it<=R)
            {
                it=st.erase(it);//it++;
            }
            if(it==st.end())
                printf("*\n");
            else
                printf("%d\n",*it);
        }
        printf("-\n");
    }
}
