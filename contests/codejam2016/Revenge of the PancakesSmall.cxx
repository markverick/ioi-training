#include<bits/stdc++.h>
using namespace std;
string s;
unordered_map<string,int> jum;
queue<string> q;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j,k,T,t;
    string s,ss;
    cin >> T;
    for(t=1;t<=T;t++)
    {
        jum.clear();
        cin >> s;
        q.emplace(s);
        jum[s]=0;
        while(!q.empty())
        {
            s=q.front();
            ss=s;
            q.pop();
            for(i=0;i<s.size();i++)
            {
                if(s[i]=='-')break;
            }
//            cout <<s<<jum[s]<<"\n";
            if(i==s.size())
            {
                printf("Case #%d: %d\n",t,jum[s]);
                break;
            }
            for(i=0;i<s.size();i++)
            {
                ss=s;
                for(j=0;j<=i;j++)
                {
                    if(s[j]=='+')
                        ss[i-j]='-';
                    else
                        ss[i-j]='+';
                }
//                cout << s << ">>" << ss << "\n";
                if(jum.find(ss)==jum.end())
                    jum[ss]=jum[s]+1,q.emplace(ss);
            }
        }
        while(!q.empty())
            q.pop();
    }
}
