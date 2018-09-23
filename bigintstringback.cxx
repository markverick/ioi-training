#include<bits/stdc++.h>
using namespace std;
class bigint {
public:
    vector<char> s;
    bigint(string x)
    {
        for(int i=x.size()-1;i>=0;i--)
            s.push_back(x[i]-'0');
    }
    bigint(vector<char> x)
    {
        s=x;
    }
    bigint(int x)
    {
        while(x>0)
            s.push_back(x%10),x/=10;
    }
    bool operator =(const bigint b)
    {
        s=b.s;
    }
    bool operator ==(const bigint b)
    {
        return s==b.s;
    }
    bool operator < (const bigint b)
    {
        if(s.size()!=b.s.size())
            return s.size()<b.s.size();
        for(int i=s.size()-1;i>=0;i--)
            return s[i]<b.s[i];
    }
    void output()
    {
        for(int i=s.size()-1;i>=0;i--)
            printf("%c",s[i]+'0');
        printf("\n");
    }
    void operator += (const bigint b)
    {
        while(s.size()<b.s.size())
            s.push_back(0);
        int tod=0,i;
        for(i=0;i<s.size();i++)
        {
            s[i]+=b.s[i]+tod;
            tod=s[i]>=10;
            s[i]%=10;
        }
        if(tod)
            s.push_back(1);
    }
    void operator *= (bigint b)
    {
        vector<char> zero,a[10];
        bigint sum(0);
        int i,j,k,tod;
        for(k=0;k<10;k++)
        {
            for(i=0;i<s.size();i++)
            {
                j=(s[i]*k+tod);
                a[k].push_back(j%10);
                printf("%d %d %d\n",k,j%10,s[i]);
                tod=j/10;
            }
            if(tod)
                a[k].push_back(tod);
        }
        for(k=0;k<10;k++)
        {
            for(j=0;j<a[k].size();j++)
                printf("%c",a[k][j]+'0');
            printf("..\n");
        }
        for(i=0;i<b.s.size();i++)
        {
            vector<char> f=zero;
            for(j=0;j<a[b.s[i]].size();j++)
                f.push_back(a[b.s[i]][j]);
            bigint p(f);
            sum+=p;
            zero.push_back(0);
        }
        s=sum.s;
    }
};
int main()
{
    int i,j,k;
    vector<bigint> v;
    v.emplace_back(823);
    v.emplace_back("73");
    v.emplace_back(72300);
    v.emplace_back(82);
    v.emplace_back("73");
    v.emplace_back("8230");
    sort(v.begin(),v.end());
    bigint sum(1);
    for(i=0;i<v.size();i++)
    {
        v[i].output();
        sum*=v[i];
    }
    sum.output();
}
