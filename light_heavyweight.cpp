#include<bits/stdc++.h>
#define MP(x,y) make_pair(x,y)
using namespace std;
set<int> st; //int=w, int=v
set<int> ::iterator it; //int=w, int=v
//pair<int,int> temp;
int val[2234567];
int temp;
int main()
{
    int n,m,i,j,k;
    char ch[2];
    int a,b;
    scanf("%d %d",&n,&m);
    for(i=0;i<n+m;i++)
    {
        //system("pause");
        scanf("%s",&ch);
        switch (ch[0])
        {
        case 'A':
            scanf("%d %d",&a,&b);
            val[a]=b;
            st.insert(a);
            break;
        case 'B':
            if(st.empty())
            {
                printf("0\n");
                break;
            }
            else
            {
                temp=val[*st.begin()];
                printf("%d\n",temp);
                st.erase(*st.begin());
                break;
            }

        case 'C':
            if(st.empty())
            {
                printf("0\n");
                break;
            }
            else
            {
                it=(st.end());
                it--;
                temp=val[*(it)];
                printf("%d\n",temp);
                st.erase(*(it));
                break;
            }

        }
    }
}
