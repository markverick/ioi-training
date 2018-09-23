#include<bits/stdc++.h>
#include<stack>
#include<string>
using namespace std;
stack<int> st;
map<stack<int>,int> hsh;
stack<int>::iterator it;
int main()
{
    int i,j,k;
    int n;
    int cot=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        st.push(1);
    }
    while(true)
    {
        if(st.size()==n)
        {
            for(i=0; hsh[st]!=0; i++)
            {
                st.pop();
            }
        }
        st.push(1);
        if(hsh[st]!=0)
        {
            st.pop();
        }
        else
        {
            cot++;
        }
        st.push(2);
        st.push(0);
        if(hsh[st]!=0)
        {
            st.pop();
            st.pop();
        }
        else
        {
            cot++;
        }
        hsh[st]++;
        printf("Count = %d\n",cot);

        system("pause");
    }


}
