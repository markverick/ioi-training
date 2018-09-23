#include<bits/stdc++.h>
using namespace std;
long long len,cot=0;
long long jum[50][50][6135];
long long hsh[6135];
vector<long long> v;
vector<char> op;
void dp(long long idx,long long level,long long val)
{
    if(jum[idx][level][val]==1)
        return;
    long long tmp=val;
    jum[idx][level][val]=1;
    if(idx==len)
    {
        if(hsh[val]==0)
            cot++;
        hsh[val]=1;
        return;
    }
    if(idx>0&&op[idx-1]=='-')
    {
        if(level%2==0)
            dp(idx+1,level+1,val-v[idx]);
        else
            dp(idx+1,level+1,val+v[idx]);
        if(level>0)
        {
            if(level%2==0)
                dp(idx+1,level-1,tmp-v[idx]);
            else
                dp(idx+1,level-1,tmp+v[idx]);
        }
        if(level%2==0)
            dp(idx+1,level,val-v[idx]);
        else
            dp(idx+1,level,val+v[idx]);
    }
    else
    {
        if(level>0)
        {
            if(level%2==0)
                dp(idx+1,level-1,val+v[idx]);
            else
                dp(idx+1,level-1,val-v[idx]);
        }
        if(level%2==0)
            dp(idx+1,level,val+v[idx]);
        else
            dp(idx+1,level,val-v[idx]);
    }

    return;
}
int main()
{
    long long i,j;
    string str;
    while(getline(cin,str))
    {
        memset(jum,0,sizeof jum);
        memset(hsh,0,sizeof hsh);
        v.clear();
        op.clear();
        cot=0;
        stringstream ss;
        string s;
        long long k;
        ss << str;
        while(ss >> k)
        {
            v.push_back(k);
            ss >> s;
            op.push_back(s[0]);
        }
        len=v.size();
        dp(0,0,3005);
        printf("%lld\n",cot);
    }
}
