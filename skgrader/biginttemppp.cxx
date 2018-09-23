#include<bits/stdc++.h>
using namespace std;
class bigint {
public:
    vector<int> dig;
    int MX=100000000;
    bigint(int x)
    {
        dig.push_back(x);
    }
    void output()
    {
        int n=dig.size();
        printf("%d",dig[--n]);
        while(n>0)printf("%08d",dig[--n]);
        printf("\n");
    }
    void operator += (const bigint &b)
    {
        int carry = 0;
        for(int i=0;i<dig.size()||i<b.dig.size()||carry;i++)
        {
            int x=carry;
            if(i<dig.size()) x+=dig[i];
            if(i<b.dig.size()) x+=b.dig[i];
            carry= x>=MX;
            if(carry) x-=MX;
            if(i<dig.size()) dig[i]=x;
            else dig.push_back(x);
        }
    }
    void operator *= (const bigint &b)
    {
        int i,j,k,l=0,tod;
        bigint sum(0),a(0);
        for(i=b.dig.size()-1;i>=0;i--)
        {
            k=b.dig[i];
            for(l=0;l<8;l++)
            {
                for(j=a.dig.size()-1;j>=0;j--)
                {
                    a.dig[j]=dig[j]*(k%10);
                    a.dig[j]+=tod;
                    tod=a.dig[j]/MX;
                    a.dig[j]%=MX;
                }
                k/=10;
            }
        }
    }
};
int main()
{

}
