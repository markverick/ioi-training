#include<bits/stdc++.h>
using namespace std;
class bigint {
public:
    string s;
    bigint(string x,int ch)
    {
        if(ch)
            s=x;
        else
            for(int i=x.size()-1;i>=0;i--)
                s.push_back(x[i]-'0');
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
    void operator += (bigint b)
    {
        while(s.size()<b.s.size())
            s.push_back(0);
        while(s.size()>b.s.size())
            b.s.push_back(0);
        int tod=0,i;
        for(i=0;i<b.s.size();i++)
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
        string zero,a[10];
        bigint sum(0);
        int i,j,k,tod;
        for(k=0;k<10;k++)
        {
            tod=0;
            for(i=0;i<s.size();i++)
            {
                j=(s[i]*k+tod);
                a[k].push_back(j%10);
                tod=j/10;
            }
            if(tod)
                a[k].push_back(tod);
        }
        for(i=0;i<b.s.size();i++)
        {
            bigint p(zero+a[b.s[i]],1);
            sum+=p;
            zero.push_back(0);
        }
        s=sum.s;
    }
};
int main()
{
    int i,j,k;
    string a,b,c;
    cin >> a >> b >> c;
    bigint x(a,0),y(b,0),z(c,0);
    x*=y;
    if(x==z)
        printf("truth");
    else
        printf("dream");
}
