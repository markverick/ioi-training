#include<bits/stdc++.h>
using namespace std;
set<int> st;
set<int>::iterator it;
int main()
{
    int n,i,j,k,idx=0;
    scanf("%d",&n);
    it=st.begin();
    for(j=0;j<n;j++)
    {
        int ch=0;
        scanf("%d",&ch);
        if(ch==1)
        {
            int a;
            scanf("%d",&a);

            st.insert(a);
            if(idx==0)
                it--;
            if(idx>0&&a>=*it)
                it--;
            idx++;
            if(idx==1)
                it=st.begin();
            if(idx%3==0)
            {
                it++;
            }
        }
        else if(ch==2)
        {

            if(idx<3)
            {
                printf("No reviews yet\n");
                continue;
            }
            int fu=0;
            it--;
            printf("%d\n",*it);
            it++;
        }
    }
}
