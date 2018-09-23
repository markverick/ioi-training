#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[1135][1135];
vector<string> v;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int r,c,i,j,k,fst,mid,lst,fk,mc=0;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
    {
        scanf("%s",s[i]+1);
    }
    fst=0;lst=r;
    while(fst<=lst)
    {
        fk=0;
        mid=(fst+lst)/2;
        string st;
        v.clear();
        for(j=1;j<=c;j++)
        {
            st.clear();
            for(i=mid;i<=r;i++)
            {
                st.push_back(s[i][j]);
            }
            v.emplace_back(st);
        }
        sort(v.begin(),v.end());
        for(i=1;i<v.size();i++)
        {
            if(v[i]==v[i-1])
            {
                fk=1;
                break;
            }
        }
        if(fk==1)
        {
            lst=mid-1;
        }
        else
        {
            mc=max(mc,mid);
            fst=mid+1;
        }
    }
    printf("%d",mc-1);
}
