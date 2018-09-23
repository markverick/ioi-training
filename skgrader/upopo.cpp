#include<bits/stdc++.h>
#define MP make_pair
using namespace std;
multiset<pair<int,int> > st;
multiset<pair<int,int> >::iterator it;
int maps[120000];
int main()
{
    scanf("%*d");
    int i,j,k;
    for(i=1;true;i++)
    {
        scanf("%d",&maps[i]);
        st.insert(MP(maps[i],i));
        if(maps[i]==0)
            break;
    }
    int len=i+1;
    while(true)
    {
        pair<int,int> p;
        it = st.end();it--;
        p=*it;
        int a=p.first; //value
        int b=p.second; //index
        st.erase(it);
        it = st.end();it--;
        p=*it;
        int c=p.first; //value
        int d=p.second; //index
        if(b>d)
        {
            it--;
            *it.first=0;
        }
        printf("%d",p.first);
    }

    //printf("%d",len);
}
