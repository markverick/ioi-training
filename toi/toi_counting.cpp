#include<bits/stdc++.h>
using namespace std;
int out[6000];
set<int> st;
set<int> ::iterator it;
int main()
{
    int oi=0;
    int idx=0;
    int n,k,i,j,m=0/*index*/,p=0;//value
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        st.insert(i);
    for(i=0;i<n;i++)
    {
        it=st.begin();
        m=(m+k-1)%(n-i);
        for(j=0;j<m;j++)
            it++;
        out[oi++]=*it;
        st.erase(it);
    }
    for(i=0;i<oi;i++)
    {
        printf("%d\n",out[i]+1);
    }
}
