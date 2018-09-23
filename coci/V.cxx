#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long x,a,b,allow[13],jum[13][3135][5];
char s[13];
vector<long long> v;
stack<long long> st;
long long dp(long long idx,long long val,long long state)
{
    if(jum[idx][val][state]>=0)return jum[idx][val][state];
    if(idx==v.size())
    {
        if(val==0)
            return 1;
        return 0;
    }
    long long sum=0,i;
    if(state==0)
    {
        for(i=0;i<v[idx];i++)
        {
            if(!allow[i])continue;
            sum+=dp(idx+1,(val*10+i)%x,1);
        }
        if(allow[v[idx]])
        {
            sum+=dp(idx+1,(val*10+v[idx])%x,0);
        }
    }
    else if(state==1)
    {
        for(i=0;i<=9;i++)
        {
            if(!allow[i])
                continue;
            sum+=dp(idx+1,(val*10+i)%x,1);
        }
    }
    else if(state==2)
    {
        for(i=1;i<v[idx];i++)
        {
            if(!allow[i])continue;
            sum+=dp(idx+1,(val*10+i)%x,1);
        }
        if(allow[v[idx]])
        {
            sum+=dp(idx+1,(val*10+v[idx])%x,0);
        }
    }
    else
    {
        for(i=1;i<=9;i++)
        {
            if(!allow[i])
                continue;
            sum+=dp(idx+1,(val*10+i)%x,1);
        }
    }
    return jum[idx][val][state]=sum;
}
int main()
{
	long long i,j,k,len,cot=0,fk,L,R;
	scanf("%lld %lld %lld",&x,&a,&b);
	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<len;i++)
        allow[s[i]-'0']=1;
    if(x>=3000)
    {
        for(i=x;i<=b;i+=x)
        {
            if(i<a)continue;
            j=i;
            fk=0;
            while(j>0)
            {
                if(!allow[j%10])
                {
                    fk=1;
                    break;
                }
                j/=10;
            }
            if(fk==0)
                cot++;
        }
        printf("%lld",cot);
    }
    else
    {
        j=a-1;
        while(j>0)
        {
            st.emplace(j%10);
            j/=10;
        }
        while(!st.empty())
            v.emplace_back(st.top()),st.pop();
        memset(jum,-1,sizeof jum);
        if(!v.empty())
            L=dp(0,0,2);
        else
            L=1;
        for(i=1;i<v.size();i++)
            L+=dp(i,0,3);
        v.clear();
        j=b;
        while(j>0)
        {
            st.emplace(j%10);
            j/=10;
        }
        while(!st.empty())
            v.emplace_back(st.top()),st.pop();
        memset(jum,-1,sizeof jum);
        if(!v.empty())
            R=dp(0,0,2);
        else
            R=1;
        for(i=1;i<v.size();i++)
            R+=dp(i,0,3);
        printf("%lld",R-L);
    }
}
