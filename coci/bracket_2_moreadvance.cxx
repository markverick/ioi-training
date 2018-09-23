#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int len,pos[12],a[12],res[12],n=0,id[222];
char s[222];
set<string> mp;
void gen(int idx)
{
    if(idx==n)
    {
        int i,st=0;
//        for(i=0;i<n;i++)
//            printf("%d",res[i]);
//        printf("\n");
        for(i=0;i<n;i++)
        {
            if(res[i]==0)
                continue;
            if(a[i]==1)
                st++;
            else
                st--;
            if(st<0)
                break;
        }
        string ss;
        if(st==0)
        {
            for(i=0;i<len;i++)
            {
                if(id[i]>=0&&res[id[i]]==0)
                    continue;
                ss.push_back(s[i]);
            }
        }
        mp.insert(ss);
        return;
    }
    res[idx]=1;
    gen(idx+1);
    res[idx]=0;
    gen(idx+1);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	scanf("%s",s);
	len=strlen(s);
	memset(id,-1,sizeof id);
	for(i=0;i<len;i++)
    {
        if(s[i]=='(')
            id[i]=n,pos[n]=i,a[n++]=1;
        if(s[i]==')')
            id[i]=n,pos[n]=i,a[n++]=0;
    }
    gen(0);
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if(*it!=s)
            cout << *it << "\n";
    }
}
